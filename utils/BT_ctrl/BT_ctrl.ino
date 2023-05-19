#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1);

const int speedPinR = 5;  // Speed control pin for Motor R
const int speedPinL = 10;  // Speed control pin for Motor B
const int dirPinA1 = 6;    // Direction control pin 1 for Motor A
const int dirPinA2 = 7;    // Direction control pin 2 for Motor A
const int dirPinB1 = 8;    // Direction control pin 1 for Motor B
const int dirPinB2 = 9;    // Direction control pin 2 for Motor B
// const int speed = 130;     // Speed of two motors, min:0, max: 255, but value exceed 200 would be the same as 200
const int Lspeed = 138; // adjust: left motor is slower, so we force it to run faster
const int Rspeed = 130; 

void forward() {
  analogWrite(speedPinR, Rspeed);
  analogWrite(speedPinL, Lspeed);
  
  digitalWrite(dirPinA1,HIGH);
  digitalWrite(dirPinA2,LOW);
  digitalWrite(dirPinB1,HIGH);
  digitalWrite(dirPinB2,LOW);
}

void forwardRight(){
  analogWrite(speedPinR, Rspeed);
  analogWrite(speedPinL, Lspeed * 1.4);

  digitalWrite(dirPinA1,HIGH);
  digitalWrite(dirPinA2,LOW);
  digitalWrite(dirPinB1,HIGH);
  digitalWrite(dirPinB2,LOW);  
}

void forwardLeft(){
  analogWrite(speedPinR, Rspeed * 1.4);
  analogWrite(speedPinL, Lspeed);

  digitalWrite(dirPinA1,HIGH);
  digitalWrite(dirPinA2,LOW);
  digitalWrite(dirPinB1,HIGH);
  digitalWrite(dirPinB2,LOW);  
}

void backward() {
  // carState = BACKWARD;
  analogWrite(speedPinR, Rspeed);
  analogWrite(speedPinL, Lspeed);

  digitalWrite(dirPinA1,LOW);
  digitalWrite(dirPinA2,HIGH);
  digitalWrite(dirPinB1,LOW);
  digitalWrite(dirPinB2,HIGH);
}

void backwardRight(){
  
  analogWrite(speedPinR, Rspeed * 1.4);
  analogWrite(speedPinL, Lspeed);

  digitalWrite(dirPinA1,LOW);
  digitalWrite(dirPinA2,HIGH);
  digitalWrite(dirPinB1,LOW);
  digitalWrite(dirPinB2,HIGH);
}

void backwardLeft(){
  
  analogWrite(speedPinR, Rspeed);
  analogWrite(speedPinL, Lspeed * 1.4);

  digitalWrite(dirPinA1,LOW);
  digitalWrite(dirPinA2,HIGH);
  digitalWrite(dirPinB1,LOW);
  digitalWrite(dirPinB2,HIGH);
}

void turnLeft() {

  analogWrite(speedPinR, Rspeed);
  analogWrite(speedPinL, 0);
  
  digitalWrite(dirPinA1,HIGH);
  digitalWrite(dirPinA2,LOW);
  digitalWrite(dirPinB1,LOW);
  digitalWrite(dirPinB2,LOW);
}

void turnRight() {
  
  analogWrite(speedPinR, 0);
  analogWrite(speedPinL, Lspeed);

  digitalWrite(dirPinA1,LOW);
  digitalWrite(dirPinA2,LOW);
  digitalWrite(dirPinB1,HIGH);
  digitalWrite(dirPinB2,LOW);
} 
void circle() { 
  
  analogWrite(speedPinR, Rspeed);
  analogWrite(speedPinL, Lspeed);

  digitalWrite(dirPinA1,HIGH);
  digitalWrite(dirPinA2,LOW);
  digitalWrite(dirPinB1,LOW);
  digitalWrite(dirPinB2,HIGH);
}  
 
void stop() {

  analogWrite(speedPinR, 0);
  analogWrite(speedPinL, 0);
  
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
  // Serial.println("Bluetooth is ready");
  
  // motor
  pinMode(speedPinR, OUTPUT);
  pinMode(speedPinL, OUTPUT);
  pinMode(dirPinA1, OUTPUT);
  pinMode(dirPinA2, OUTPUT);
  pinMode(dirPinB1, OUTPUT);
  pinMode(dirPinB2, OUTPUT);
}
void loop()
{
    if(BT.available()) {
      // delay(3);
      char ch = BT.read();
      Serial.print(ch);
      switch (ch)
      {
          case 'F':
              forward();
              break;
          case 'B':
              backward();
              break;
          case 'L':
              turnLeft();
              break;
          case 'R':
              turnRight();
              break;
          case 'S':
              stop();
              break;
          case 'I':
              forwardRight();
              break;
          case 'G':
              forwardLeft();
              break;
          case 'J':
              backwardRight();
              break;
          case 'H':
              backwardLeft();
              break;
          default:
              // stop();
              break;
      }
    }
    delay(100);

}