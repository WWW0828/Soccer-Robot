int motor_left_1 = 10, motor_left_2 = 9;
int motor_right_1 = 6, motor_right_2 = 5;
int speed = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor_left_1, OUTPUT);
  pinMode(motor_left_2, OUTPUT);
  pinMode(motor_right_1, OUTPUT);
  pinMode(motor_right_2, OUTPUT);
  Serial.begin(9600);
}

void turnLeft(int speed) {
  Serial.println("turn left");
  analogWrite(motor_left_1, 0);
  analogWrite(motor_left_2, 0);
  analogWrite(motor_right_1, speed);
  analogWrite(motor_right_2, 0);
}

void turnRight(int speed) {
  Serial.println("turn right");
  analogWrite(motor_left_1, speed);
  analogWrite(motor_left_2, 0);
  analogWrite(motor_right_1, 0);
  analogWrite(motor_right_2, 0);
}

void Forward(int speed) {
  Serial.println("forward");
  analogWrite(motor_left_1, speed);
  analogWrite(motor_left_2, 0);
  analogWrite(motor_right_1, speed);
  analogWrite(motor_right_2, 0);
}

void Backward(int speed) {
  Serial.println("backward");
  analogWrite(motor_left_1, 0);
  analogWrite(motor_left_2, speed);
  analogWrite(motor_right_1, 0);
  analogWrite(motor_right_2, speed);
}

void Stop() {
  Serial.println("stop");
  analogWrite(motor_left_1, 0);
  analogWrite(motor_left_2, 0);
  analogWrite(motor_right_1, 0);
  analogWrite(motor_right_2, 0);
}

void loop() {
  turnLeft(speed);
  delay(2000);
  turnRight(speed);
  delay(2000);
  Forward(speed);
  delay(2000);
  Backward(speed);
  delay(2000);
  Stop();
  delay(2000);
}
