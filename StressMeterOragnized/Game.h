int stresslevel=0;
int gamecount=0;
long timeSinceMorse=-30000;
int answer=2;
bool gamedone=false;

const int greenLED = 3;
const int yellowLED = 5;
const int redLED = 6;

#define POT A2
int potValue;

void game_read_pot(){
  answer=2;
  potValue=analogRead(POT);                /// Read first GSR value and add it to the sum
  delay(10);
  potValue=analogRead(POT);
  delay(10);

  potValue=map(potValue, 0 , 1022, 0, 10);

  if(potValue > 0 )
    {Serial.println(potValue);
    }

   if(potValue==number && potValue !=0 && gamedone==false)
     {answer=1;
     lcd_right_answer();
     timeSinceMorse-=30000;
     }
   if(potValue != number && potValue !=0 && gamedone==false )
      {
        answer=0;
        lcd_wrong_answer();
        timeSinceMorse-=30000;
      }
}

void game_calculate_stress(){
  stresslevel=int( ((deltaDiffGSR * 0.7) + ( deltaDiffHBS * 1.3 )) / 2  );
  Serial.print("Stress level is: ");
  Serial.println(stresslevel);
  if(stresslevel <=20)
    analogWrite(greenLED,70);
  else
    analogWrite(greenLED,0);

  if(stresslevel >=21 && stresslevel <=50)
    analogWrite(yellowLED, 70);
    else
    analogWrite(yellowLED, 0);

  if(stresslevel >=51)
    analogWrite(redLED, 70);
    else
    analogWrite(redLED, 0);

}

void game_morse(){

  if(stresslevel <=20 && millis()-timeSinceMorse >= 60000 && gamecount<=3){
    if(gamecount!=0)
      lcd_next_round();
    morse_choose_word(1);
    timeSinceMorse=millis();
    gamecount++;
  }
  if(stresslevel>=21 && stresslevel <=50 && millis()-timeSinceMorse >= 60000 && gamecount<=3){
    if(gamecount!=0)
      lcd_next_round();
    morse_choose_word(2);
    timeSinceMorse=millis();
    gamecount++;
  }
  if(stresslevel>=51 && millis()-timeSinceMorse >= 60000 && gamecount<=3){
    if(gamecount!=0)
      lcd_next_round();
    morse_choose_word(3);
    timeSinceMorse=millis();
    gamecount++;
  }

  if(gamecount==4 && millis()-timeSinceMorse >= 60000){
    lcd_end_game();
    gamedone=true;
    gamecount=5;
  }

}
