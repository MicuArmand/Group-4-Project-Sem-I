#include <Entropy.h>                      /// Library for creating truly RANDOM numbers
#include <cww_MorseTx.h>                  /// Library for the morse code

#define CW_SPEED 12
#define PIN_LED 9
#define PIN_SND 8
#define TONE_FREQ 4000

// Construct a cww_MorseTx instance that will send Morse Code at 15 words
// per minute on I/O pin 2. Output is active HIGH.
cww_MorseTx morse(PIN_LED, CW_SPEED, PIN_SND, TONE_FREQ);


int number;                                     /// Variable to store a random number to call a random function

void morse_send_word1(int level) {
  Serial.println("WORD 1");
  if(level==1)
    morse.send("G    O    R    F");
  if(level==2)
    morse.send("E   S   A   B");
  if(level==3)
    morse.send("L  L  I  K");
}

void morse_send_word2(int level) {
  Serial.println("WORD 2");
  if(level==1)
    morse.send("D    R    I    B");
  if(level==2)
    morse.send("K   S   A   M");
  if(level==3)
    morse.send("S  N  U  G");
}

void morse_send_word3(int level) {
  Serial.println("WORD 3");
  if(level==1)
    morse.send("K    R    A    D");
  if(level==2)
    morse.send("P   M   A   C");
  if(level==3)
    morse.send("A  E  R  A");
}

void morse_send_word4(int level) {
  Serial.println("WORD 4");
  if(level==1)
    morse.send("G    N    I    R    ");
  if(level==2)
    morse.send("L   L   E   H");
  if(level==3)
    morse.send("B  M  O  B");
}

void morse_send_word5(int level) {
  Serial.println("WORD 5");
  if(level==1)
    morse.send("N    O    I    L");
  if(level==2)
    morse.send("T   S   E   T");
  if(level==3)
    morse.send("K  E  E  S");
}

void morse_send_word6(int level) {
  Serial.println("WORD 6");
  if(level==1)
    morse.send("K    R    A    D");
  if(level==2)
    morse.send("D   U   O   L");
  if(level==3)
    morse.send("E  R  I  W");
}

void morse_send_word7(int level) {
  Serial.println("WORD 7");
  if(level==1)
    morse.send("N    I    A    P");
  if(level==2)
    morse.send("K   C   E   D");
  if(level==3)
    morse.send("G  N  I  K");
} 

void morse_send_word8(int level) {
  Serial.println("WORD 8");
  if(level==1)
    morse.send("E    V    A    S");
  if(level==2)
    morse.send("S   D   D   A");
  if(level==3)
    morse.send("W  E  R  C");
}

void morse_send_word9(int level) {
  Serial.println("WORD 9");
  if(level==1)
    morse.send("S    M    R    A");
  if(level==2)
    morse.send("N   I   A   R");
  if(level==3)
    morse.send("T  I  D  E");
}

void morse_send_word10(int level) {
  Serial.println("WORD 10");
  if(level==1)
    morse.send("R    A    E    F");
  if(level==2)
    morse.send("T   S   I   F");
  if(level==3)
    morse.send("E  R  I  F");
}

void (*functionPointer[])(int level) = {morse_send_word1, morse_send_word2, morse_send_word3, 
                                        morse_send_word4, morse_send_word5, morse_send_word6, 
                                        morse_send_word7, morse_send_word8, morse_send_word9, morse_send_word10 };

void morse_choose_word(int level){

  number=Entropy.random(1,11);
  functionPointer[number](level);
    
}
