LiquidCrystal_I2C lcd(0x27,16,2);     /// Create LCD object ( 4 pin I2c )

void lcd_checkup(){
  
  lcd.setCursor(0,0);
  lcd.print("  INITIALIZING");
  lcd.setCursor(0,1);
  lcd.print("       .");
  delay(600);
  lcd.print(".");
  delay(600);
  lcd.print(".");
  delay(600);
  
  for(int i=0; i<3; i++)
  {
    lcd.clear();
    delay(300);
    lcd.print("      DONE     ");
    delay(300);
    
  }
  lcd.clear();
}

void lcd_baseline_check(){
  lcd.print("Getting baseline values");
  lcd.setCursor(0,1);
  lcd.print("Breathe normally");
  delay(100);
}

void lcd_baseline_done(){
  lcd.clear();
  lcd.print("Got baseline value");
  delay(100);
  lcd.clear();
}

int lcd_print_bpm(int avg){
  lcd.setCursor(0,1);
  lcd.print("Your BPM: ");                          /// Print the value of the BPM on the LCD
  lcd.print(avg);
  Serial.print("Your BPM: ");                   /// Print the value of the BPM in Serial Monitor
  Serial.println(avg);
}

float lcd_print_diff(float deltaDiffGSR){
    lcd.setCursor(0,0);
    lcd.print("Delta GSR:");
    lcd.print(deltaDiffGSR);
    lcd.print("%");
}
