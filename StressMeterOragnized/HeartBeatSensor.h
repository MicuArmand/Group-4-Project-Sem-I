#define HBS A1
const int THRESHOLD = 450;              /// Threshold of the HBS analog reading. This is used to find an actual pulse. If there is too much noise, adjust the value from here.

int beatTimeOld = 0;                    /// This variable holds the time of a last-read heartbeat
int beatTimeNew = 0;                    /// This variable stores the time of the new-read heartbeat

int interval = 0;                       /// Interval of time between 2 beats

float bpmNew = 0.0;                     /// The BPM of the most recent 2 readings
float bpmOld = 0.0;                     /// The BPM of the last 2 readings

int okHBS = 0;                          /// Variable that counts the readings to help average the BPM every 2 times
float BPM = 0.0;                        /// The BPM average of the _new nad _old

bool IgnoreReading = false;             /// This means that after a heartbeat is detected, the variable is set to "true", 
                                        /// so it doesn't read the same heartbeat multiple times, and it's reset back to false when the value is again below the threshold
                                         
float bpmAverage[3];                    /// Because having only the "BPM" variable caused a lot of fluctuation in the displayed BPM (going between 60 and 90 almost every time),
int index = 0;                          /// I decided to include an array of 3 averages to average AGAIN, and a index to keep overwriting new values of different positions of the vector
int avg = 0;                            /// avg = (bpmAverage[0] + bpmAverage[1] + bpmAverage[2]) / 3
int count = 0;                          /// Counts how many heartbeats have happened

float deltaDiffHBS=0.0;                 /// The differance in percentage between the baseline value and the actual value

void heartbeat_find(){
 
    beatTimeNew = millis();                           /// Saves the time of the new heartbeat
    interval = beatTimeNew - beatTimeOld;             /// Calculate the interval of time between the new and the old heartbeat
    
    bpmNew = (1.0/interval) * 60.0 * 1000;            /// Update the new current BPM
    
    okHBS++;                                          /// Increment ok to help average the BPM every 2 readings

    bpmOld = bpmNew;                                  /// Update the old BPM
    beatTimeOld = beatTimeNew;                        /// Update the old and new reading times
    
    IgnoreReading=true;                               /// Ignore every reading above threshold. This helps not read the same heartbeat multiple times
   
}

void heartbeat_show(){
  
    okHBS = 0;
    BPM = (bpmOld + bpmNew) / 2;
    
    if( BPM >= 50 && BPM <= 150 ){
      bpmAverage[index] = BPM;
      
      float total=0.0;
      
      for(int i=0; i<3; i++){
        total+=bpmAverage[i];
      }
      
      avg = (int) total/3;
      
      lcd_print_bpm(avg);                             /// PROBLEM             

      index = (index + 1) % 3;

      deltaDiffHBS=((avg/60)-1) * 100;
    }
}
