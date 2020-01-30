#define GSR_0 A0                        /// Declaring the analog inputs of the sensors
#define GSR_1 A1                        /// GSR = GALVANIC SKIN RESPONSE

int gsrValue=0;                         /// The analog sensor reading of the first GSR

int gsrAverage=0;                       /// The average of 10 GSR_0 readings, to remove imperfections and smooth out the reading.

long sum=0;                             /// The variable that stores the 10 readings for average

int okGSR=0;                            /// The variable that keeps track of the number of readings done before averaging

float gsrBaseline=0.0;                  /// Setting up the baseline for the GSR readings
float deltaDiffGSR=0.0;

unsigned long lastReadGSR;              /// Timer for GSR readings 

void gsr_baseline_check(){              ///Function that makes the sum of the first gsr readings to create a baseline afterwards
    gsrValue=analogRead(GSR_0);                
    delay(10);
    gsrValue=analogRead(GSR_0);
    delay(10);
    gsrBaseline += gsrValue;
}

void gsr_read(){
  
    gsrValue=analogRead(GSR_0)  ;                /// Read first GSR value and add it to the sum
    delay(10);
    gsrValue=analogRead(GSR_0);
    delay(10);
    sum += gsrValue;
    
    okGSR++;                                   /// Increment step
    lastReadGSR=millis();                      /// Update the timer because this was the last reading
}

void gsr_make_average(){
  
    gsrAverage = sum/10;                     
    okGSR = 0;
    sum = 0;                                   /// The number of readings and the sum reset

    deltaDiffGSR = ((gsrBaseline/gsrAverage)-1)*100;
    
    lcd_print_diff(deltaDiffGSR);
    
    Serial.print("The GSR Baseline is: ");
    Serial.println(gsrBaseline);
    Serial.print("The GSR Difference between baseline and actual is: ");
    Serial.println(deltaDiffGSR);
    Serial.print("The 1st GSR reading is: ");
    Serial.print(gsrAverage);   
    Serial.println(" ");
    Serial.println(" ");
    
}
