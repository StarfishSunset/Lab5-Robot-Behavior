#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3


int IRSensor1 = 11; // IR sensor connected to OUT PIN 11
int IRSensor2 = 12; // IR sensor connected to OUT PIN 12
int E1 = 5;
int E2 = 6;
int M1 = 7;
int M2 = 4;

void setup() {
  Serial.begin(57600);
  pinMode (IRSensor1, INPUT); //IRSensor1 is INPUT
  pinMode (IRSensor2, INPUT); //IRSensor2 is also INPUT
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);
}

void loop() {
  int statusSensor1 = digitalRead (IRSensor1);
  int statusSensor2 = analogRead (IRSensor2);

  Serial.print(digitalRead(11));
  Serial.println(digitalRead(12));

  analogWrite(trigPin, LOW);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  analogWrite(trigPin, LOW);

if (statusSensor1 == 0)
  {
    advance1(120, 120);
  }
  
  else if (statusSensor1 == 1) {
    delay(10);
    Serial.println("working");
    stop2();
  }

  delay(1);

if (statusSensor2 == 0) 
{
  advance1(120, 120);
}
  else if (statusSensor2 == 1) {
    delay(10);   
    stop1();
    Serial.println("fml");
  }
}


void advance1(char a, char b)         //Move forward
{
  analogWrite (E1, a);     //PWM Speed Control
  digitalWrite(M1, HIGH);
  analogWrite (E2, b);
  digitalWrite(M2, HIGH);
}

//void advance2(char a, char b)         //Move forward
//{
//  analogWrite (E1, a);     //PWM Speed Control
//  digitalWrite(M1, LOW);
//  analogWrite (E2, b);
//  digitalWrite(M2, HIGH);
//}
void stop1(void) {
  digitalWrite(E1, LOW);
}
void stop2(void) {
   digitalWrite(E2, LOW);
}
