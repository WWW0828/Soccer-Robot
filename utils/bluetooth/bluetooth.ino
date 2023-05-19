#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Bluetooth is ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(BT.available()) {
    delay(3);
    char ch = BT.read();
    Serial.println(ch);
  }
}
