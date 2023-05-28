/*
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 display() and noDisplay() functions to turn on and off
 the display.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

*/

// include the library code:
// #include <LiquidCrystal.h>
#include <LiquidCrystal_PCF8574.h>
#include <stdlib.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
// const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
// or lcd(0x3F);
int sensorPin = A0;
float outputMsg;
int debounce_delay = 150;
int black_score = 0;
int white_score = 0;

int black_btn = 3;
int white_btn = 4;
int reset = 5;

// int light = A1;
void setup() {
  // set up the LCD's number of columns and rows:
  // pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(100);
  lcd.noDisplay();
  // Print a message to the LCD.
  // lcd.print("hello, world!");
}

int debounce(int pin) {
    int prev_state = 0;
    int current_state = digitalRead(pin);
    if (current_state != prev_state){
        delay(debounce_delay);
        current_state = digitalRead(pin);
    }
    prev_state = current_state;
    return current_state;
}
void loop() {
  lcd.display();
  lcd.setCursor(0, 0);

  lcd.print("Black      White");
  lcd.setCursor(0, 1);
  lcd.print("  ");
  lcd.print(black_score);  
  lcd.print("          ");
  lcd.print(white_score);
    if(debounce(black_btn)){
        black_score++;
        Serial.print("black:");
        Serial.println(black_score);
    }
    if(debounce(white_btn)){
        white_score++;
        Serial.print("white:");
        Serial.println(white_score);
    }
  

}

