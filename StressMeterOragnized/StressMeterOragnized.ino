#include <Entropy.h>                  /// Library for creating truly RANDOM numbers
#include <LiquidCrystal_I2C.h>        /// LCD screen library with I2c communication protocol
#include <Wire.h>
#include <Arduino.h>

#include "LCDScreen.h"
#include "GSRSensor.h"
#include "HeartBeatSensor.h"
#include "MorseCode.h"
#include "Game.h"

#define USE_ARDUINO_INTERRUPTS true       /// Set-up low-level interrupts for most acurate BPM math.
#define HBS A2                            /// Declaring the analog input of the Heart Beat Sensor


void led_checkup(){
  analogWrite(greenLED, 100);
  delay(1000);
  analogWrite(yellowLED, 70);
  delay(1000);
  analogWrite(redLED, 70);
  delay(1000);
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  
  }


void setup() {
  Serial.begin(9600);                     /// Baud rate set to 9600 bits per second
  
  pinMode(10, INPUT);                     /// Setup for leads off detection LO +
  pinMode(11, INPUT);                     /// Setup for leads off detection LO -
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  

  Entropy.initialize();
  
  lastReadGSR = millis();

  lcd.init();                             /// Initialize LCD screen
  lcd.backlight();
  lcd_checkup();                          /// Call fancy-pants LCD testing function
  led_checkup();
  lcd_baseline_check();                   /// Print on LCD the "Checking baseline" text
  
  for(int i=0; i<20; i++)
  {
    gsr_baseline_check();                 /// Actually call the baseline check function to find the baseline
    delay(500);  
  }

  gsrBaseline = gsrBaseline/20;           /// The sum of all 20 readings is divided by 20 to get an average and it's globally set as the GSR baseline
  
  lcd_baseline_done();                    /// Print the "Baseline Received" text

  lcd_game_start();

}


void loop() {
  
  if(analogRead(HBS) > THRESHOLD && IgnoreReading == false) {   /// If a heartbeat is detected, run the  function
    heartbeat_find();
  }
  
  if(analogRead(HBS) < THRESHOLD){
    IgnoreReading=false;
  }
      
  delay(5);
      
  if(okHBS == 2)                                 /// Save BPM and display it every 2 current BPM updates
  {
    heartbeat_show();
  }


  if(millis()-lastReadGSR >= 50)                 /// Read a new GSR value only every 50ms, and it adds it to the sum. Ok increases by one to signify that 1 reading has been stored.
  {
    gsr_read();
  }
  

  if(okGSR == 10)
  {                                              /// If there have been 10 readings, they would be averaged.
    gsr_make_average();
  }
   
  game_calculate_stress();
  game_morse();

  game_read_pot();

}
