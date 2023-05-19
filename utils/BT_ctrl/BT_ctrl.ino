#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1);

const int speedPinA = 5;  // Speed control pin for Motor A
const int speedPinB = 10;  // Speed control pin for Motor B
const int dirPinA1 = 6;    // Direction control pin 1 for Motor A
const int dirPinA2 = 7;    // Direction control pin 2 for Motor A
const int dirPinB1 = 8;    // Direction control pin 1 for Motor B
const int dirPinB2 = 9;    // Direction control pin 2 for Motor B
const int speed = 130;     // Speed of two motors, min:0, max: 255, but value exceed 200 would be the same as 200

void forward() {
  
  analogWrite(speedPinA, speed);
  analogWrite(speedPinB, speed);
  
  digitalWrite(dirPinA1,HIGH);
  digitalWrite(dirPinA2,LOW);
  digitalWrite(dirPinB1,HIGH);
  digitalWrite(dirPinB2,LOW);
}

void backward() {
  analogWrite(speedPinA, speed);
  analogWrite(speedPinB, speed);

  digitalWrite(dirPinA1,LOW);
  digitalWrite(dirPinA2,HIGH);
  digitalWrite(dirPinB1,LOW);
  digitalWrite(dirPinB2,HIGH);
}

void turnRight() {

  analogWrite(speedPinA, speed);
  analogWrite(speedPinB, 0);
  
  digitalWrite(dirPinA1,HIGH);
  digitalWrite(dirPinA2,LOW);
  digitalWrite(dirPinB1,LOW);
  digitalWrite(dirPinB2,LOW);
}

void turnLeft() {
  
  analogWrite(speedPinA, 0);
  analogWrite(speedPinB, speed);

  digitalWrite(dirPinA1,LOW);
  digitalWrite(dirPinA2,LOW);
  digitalWrite(dirPinB1,HIGH);
  digitalWrite(dirPinB2,LOW);
} 
void circle() { 
  
  analogWrite(speedPinA, speed);
  analogWrite(speedPinB, speed);

  digitalWrite(dirPinA1,HIGH);
  digitalWrite(dirPinA2,LOW);
  digitalWrite(dirPinB1,LOW);
  digitalWrite(dirPinB2,HIGH);
}  
 
void stop() {

  analogWrite(speedPinA, 0);
  analogWrite(speedPinB, 0);
  
  digitalWrite(dirPinA1,LOW);
  digitalWrite(dirPinA2,LOW);
  digitalWrite(dirPinB1,LOW);
  digitalWrite(dirPinB2,LOW);
} 
 
void setup() 
{ 
  // Bluetooth
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Bluetooth is ready");
  
  // motor
  pinMode(speedPinA, OUTPUT);
  pinMode(speedPinB, OUTPUT);
  pinMode(dirPinA1, OUTPUT);
  pinMode(dirPinA2, OUTPUT);
  pinMode(dirPinB1, OUTPUT);
  pinMode(dirPinB2, OUTPUT);
}
void loop()
{
    while(BT.available()) {
      delay(3);
      char ch = BT.read();
      // Serial.println(ch);
      switch (ch)
      {
          case 'f':
              forward();
              delay(50);
              break;
          case 'b':
              backward();
              delay(50);
              break;
          case 'l':
              turnRight();
              delay(50);
              break;
          case 'r':
              turnLeft();
              delay(50);
              break;
          
          default:
              stop();
              break;
      }
      stop();
    }
}