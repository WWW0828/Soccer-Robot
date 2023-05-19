int trigPin = 11;  
int echoPin = 12;  
long duration, cm; 
int T = 30;
float sos(int t){
    float c = 331.5 + 0.607 * t;
    float v = 10000/c;
    return v;
}

void setup()
{
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    cm = (duration / 2) / sos(T);

    Serial.print(cm); 
    Serial.println(" cm");

    delay(100);
}