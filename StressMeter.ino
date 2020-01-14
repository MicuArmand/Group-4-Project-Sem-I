#include <PulseSensorPlayground.h>        /// Include the offical library from PulseSensor.com for easier coding
#define USE_ARDUINO_INTERRUPTS true       /// Set-up low-level interrupts for most acurate BPM math.
#define GSR_0 A0                    /// Declaring the analog inputs of the sensors
#define GSR_1 A1                    /// GSR = GALVANIC SKIN RESPONSE
#define HBS_0 A2                    /// HBS = HEART BEAT SENSOR
#define HBS_1 A3
unsigned long last_read_HBS;             /// Timer for HBS readings
unsigned long last_read_GSR;             /// Timer for GSR readings 

const int hbs_0_led = 3;            /// Fading LEDs that will blink every heartbeat. NOTE : THE PINS MUST BE CAPABLE OF PWM.
const int hbs_1_led = 5;

int baseline_0=0;                     /// Set a baseline of BPM to see changes of stress level in time
int baseline_1=0;                     /// For now I haven't implemented this. Will do after some testing

const int PULSE_SENSOR_COUNT = 2;
PulseSensorPlayground pulseSensor(PULSE_SENSOR_COUNT);        /// Creates an instance of the "PulseSensorPlayground" object called "pulseSensor"

const int THRESHOLD = 550;          /// Threshold of the HBS analog reading. This is used to find an actual pulse. If there is too much noise, adjust the value from here.


int gsr_0_value=0;            /// The analog sensor reading of the first GSR
int gsr_1_value=0;            /// The analog sensor reading of the second GSR

int gsr_0_average=0;          /// The average of 10 GSR_0 readings, to remove imperfections and smooth out the reading.
int gsr_1_average=0;          /// The average of 10 GSR_1 readings, to remove imperfections and smooth out the reading.

long sum_0=0;                 /// The variable that stores the 10 readings for average
long sum_1=0;

int ok=0;                     /// The variable that keeps track of the number of readings done before averaging


 
 void setup() {
  Serial.begin(9600);                               /// Baud rate set to 9600 bits per second ( Considering 28 800 after some testing. Gotta go fast !)

  pinMode(hbs_0_led, OUTPUT);                       /// Declaring fading LEDs as outputs
  pinMode(hbs_1_led, OUTPUT);
  
  pulseSensor.analogInput(HBS_0, 0);                /// Declaring the analog input of the HBS for the library to use (  
  pulseSensor.fadeOnPulse(hbs_0_led, 0);            /// Declaring fading LED of the first HBS. This will make it blink and fade every beat.

  pulseSensor.analogInput(HBS_1, 1);                /// Declaring the analog input of the HBS for the library to use
  pulseSensor.fadeOnPulse(hbs_1_led, 1);            /// Declaring fading LED of the second HBS. This will make it blink and fade every beat.

  
  pulseSensor.setThreshold(THRESHOLD);              /// Set the threshold
  
  last_read_HBS=millis();
  last_read_GSR=millis();

  delay(1000);

  
}




void loop() {

  int BPM_0 = pulseSensor.getBeatsPerMinute(0);         /// Calls function on our pulseSensor object that returns BPM as an "int".
  int BPM_1 = pulseSensor.getBeatsPerMinute(1);         /// "BPM_0" and "BPM_1" hold this values now.
  
  if(millis()-last_read_HBS>=20){
    for (int i = 0; i < PULSE_SENSOR_COUNT; i++) 
      {
      if (pulseSensor.sawStartOfBeat(i)){
        pulseSensor.outputBeat(i);
        Serial.println("A heartbeat happened ! ");      /// If a beat happens, it will output that,
        if(i==0)                                        ///
        {                                               /// and display the current BPM of the sensor
          Serial.print("BPM of the 1st sensor: ");      ///
          Serial.println(BPM_0);
        }
        if(i==1)
        {
          Serial.print("BPM of the 2nd sensor: ");
          Serial.println(BPM_1);
        }
        
        Serial.println(" ");

        last_read_HBS=millis();
      }
      }
      
  }

  
  if(millis()-last_read_GSR>=10)                   /// Read a new GSR value only every 5ms, and it adds it to the sum. Ok increases by one to signify that 1 reading has been stored.
  {
    gsr_0_value=analogRead(GSR_0);                /// Read first GSR value and add it to the sum
    sum_0 += gsr_0_value;
    
    gsr_1_value=analogRead(GSR_1);                /// Read second GSR value and add it to the sum
    sum_1 += gsr_1_value;
    
    ok++;                                   /// Increment step
    last_read_GSR=millis();                     /// Update the timer because this was the last reading
  }
  

  if(ok==10){
    gsr_0_average=sum_0/10;                     /// If there have been 10 readings, they would be averaged.
    gsr_1_average=sum_1/10;
    ok=0;
    sum_0=0;                                    /// The number of readings and the sum reset.
    sum_1=0;

    Serial.print("The 1st GSR reading is: ");
    Serial.println(gsr_0_average);              /// Print in the serial the average for troubleshooting
    Serial.print("The 2nd GSR reading is: ");
    Serial.println(gsr_1_average); 
    Serial.println(" ");
    Serial.println(" ");
    
  }
  

  

}
