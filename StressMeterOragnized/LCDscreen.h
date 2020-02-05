LiquidCrystal_I2C lcd(0x27,16,2);     /// Create LCD object ( 4 pin I2c )

void lcd_checkup(){
  
  lcd.setCursor(0,0);
  lcd.print("  INITIALIZING");
  Serial.println("INITIALIZING LCD");
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



void lcd_game_start(){

  Serial.println("Game starting");
  for(int i=0; i<4; i++)
  {
    lcd.clear();
    delay(100);
    lcd.print("     Welcome");
    delay(200);  
  }
  lcd.clear();
  lcd.print("Game starting in");
  lcd.setCursor(0,1);
  lcd.print("       3");
  delay(1000);
  lcd.clear();
  lcd.print("Game starting in");
  lcd.setCursor(0,1);
  lcd.print("       2");
  delay(1000);
  lcd.clear();
  lcd.print("Game starting in");
  lcd.setCursor(0,1);
  lcd.print("       1");
  delay(1000);
  lcd.clear();
  lcd.print("      LIVE");
  delay(200);
  lcd.clear();
  delay(100);
  lcd.print("      LIVE");
  delay(200);
  lcd.clear();
  delay(100);
  lcd.print("      LIVE");
  delay(200);
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
  lcd.print("  Baseline set");
  delay(1000);
  lcd.clear();
}

void lcd_next_round()
{
  lcd.clear();
  lcd.print("Prepare for next");
  lcd.setCursor(0,1);
  lcd.print("     round!");
  delay(5000);


  
  lcd.clear();
  lcd.print(" Next round in:");
  lcd.setCursor(0,1);
  lcd.print("       3");
  delay(1000);
  
  lcd.clear();
  lcd.print(" Next round in:");
  lcd.setCursor(0,1);
  lcd.print("       2");
  delay(1000);
  
  lcd.clear();
  lcd.print(" Next round in:");
  lcd.setCursor(0,1);
  lcd.print("       1");
  delay(1000);
  
  lcd.clear();
}

void lcd_right_answer(){

  for(int i=0; i<5; i++){
  lcd.clear();
  lcd.print("     MISSLE");
  lcd.setCursor(0,1);
  lcd.print("  INTERCEPTED!");
  delay(1000);
  lcd.clear();
  delay(200);
  }
  
}

void lcd_end_game(){
  lcd.clear();
  lcd.print("Thx for playing!");
  lcd.setCursor(0,1);
  lcd.print("    Monitor:");
  delay(4000);
  lcd.clear();
}

void lcd_wrong_answer(){

  for(int i=0; i<5; i++){
  lcd.clear();
  lcd.print("      CITY");
  lcd.setCursor(0,1);
  lcd.print("   DESTROYED!");
  delay(1000);
  lcd.clear();
  delay(200);
  }
  
  
}
int lcd_print_bpm(int avg){
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("Your BPM: ");                          /// Print the value of the BPM on the LCD
  lcd.print(avg);
  Serial.print("Your BPM: ");                   /// Print the value of the BPM in Serial Monitor
  Serial.println(avg);
}

float lcd_print_diff(float deltaDiffGSR){
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Delta GSR:");
    lcd.print(deltaDiffGSR);
    lcd.print("%");
}
