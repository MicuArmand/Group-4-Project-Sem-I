#include <Entropy.h>                      /// Library for creating truly RANDOM numbers
#include <cww_MorseTx.h>                  /// Library for the morse code

#define CW_SPEED 12
#define PIN_LED 12
#define PIN_SND 8
#define TONE_FREQ 3000

// Construct a cww_MorseTx instance that will send Morse Code at 15 words
// per minute on I/O pin 2. Output is active HIGH.
cww_MorseTx morse(PIN_LED, CW_SPEED, PIN_SND, TONE_FREQ);


int number;                                     /// Variable to store a random number to call a random function

void morse_send_word1(int level) {
  Serial.println("WORD 1");
  tone(8, 2000, 500);
  delay(3000);
  if(level==1)
    morse.send("M    A    E    T");
  if(level==2)
    morse.send("Y   E   R   P");
  if(level==3)
    morse.send("S  R  A  L");
   tone(8, 2000, 500);
}

void morse_send_word2(int level) {
  Serial.println("WORD 2");
  tone(8, 2000, 500);
  delay(3000);
  if(level==1)
    morse.send("E    M    O    S");
  if(level==2)
    morse.send("R   E   T   A   W");
  if(level==3)
    morse.send("Y  R  F");

   tone(8, 2000, 500);
}

void morse_send_word3(int level) {
  Serial.println("WORD 3");
  tone(8, 2000, 500);
  delay(3000);
  if(level==1)
    morse.send("T    X    E    N");
  if(level==2)
    morse.send("E   N   I   M");
  if(level==3)
    morse.send("E  S  A  B");
   tone(8, 2000, 500);
}

void morse_send_word4(int level) {
  Serial.println("WORD 4");
  tone(8, 2000, 500);
  delay(3000);
  if(level==1)
    morse.send("E    N    O    Z");
  if(level==2)
    morse.send("A   Z   I   L");
  if(level==3)
    morse.send("B  M  O  B");
   tone(8, 2000, 500);
}

void morse_send_word5(int level) {
  Serial.println("WORD 5");
  tone(8, 2000, 500);
  delay(3000);
  if(level==1)
    morse.send("E    T    Y    B");
  if(level==2)
    morse.send("E   M   A   T");
  if(level==3)
    morse.send("E  R  I  F");
   tone(8, 2000, 500);
}

void morse_send_word6(int level) {
  Serial.println("WORD 6");
  tone(8, 2000, 500);
  delay(3000);
  if(level==1)
    morse.send("N    O    O    M");
  if(level==2)
    morse.send("D   N   O   U   S");
  if(level==3)
    morse.send("A  N  E  L");
   tone(8, 2000, 500);
}

void morse_send_word7(int level) {
  Serial.println("WORD 7");
  tone(8, 2000, 500);
  delay(3000);
  if(level==1)
    morse.send("O    G    N    A    M");
  if(level==2)
    morse.send("N   O   O   N");
  if(level==3)
    morse.send("E  T  I  R  W");
   tone(8, 2000, 500);
} 

void morse_send_word8(int level) {
  Serial.println("WORD 8");
  tone(8, 2000, 500);
  delay(3000);
  if(level==1)
    morse.send("W    A    R    D");
  if(level==2)
    morse.send("T   A   E   M");
  if(level==3)
    morse.send("T  A   E   N");
   tone(8, 2000, 500);
}

void morse_send_word9(int level) {
  Serial.println("WORD 9");
  tone(8, 2000, 500);
  delay(3000);
  if(level==1)
    morse.send("N    A    M    T    N    A");
  if(level==2)
    morse.send("E   M   I   T");
  if(level==3)
    morse.send("R  U  O  S");
   tone(8, 2000, 500);
}

void morse_send_word10(int level) {
  Serial.println("WORD 10");
  tone(8, 2000, 500);
  delay(3000);
  if(level==1)
    morse.send("E    T    U    N    I    M");
  if(level==2)
    morse.send("G   N   I   X   O   B");
  if(level==3)
    morse.send("V  A  E  N");
   tone(8, 2000, 500);
}

void (*functionPointer[])(int level) = {morse_send_word1, morse_send_word2, morse_send_word3, 
                                        morse_send_word4, morse_send_word5, morse_send_word6, 
                                        morse_send_word7, morse_send_word8, morse_send_word9, morse_send_word10 };

void morse_choose_word(int level){

  number=Entropy.random(1,11);
  functionPointer[number](level);
    
}
