#include <Servo.h>

// Defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;
const int servoPin = 6; 
 // Change this to the appropriate pin for your servo
const int moisturePin = A0;
// Defines variables
long duration;
int distance;
int safetyDistance;
int maxSafetyDistance;
const int switchPin = 7;
const int vibro=8;
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(vibro,OUTPUT);
  Serial.begin(9600);

  Serial.begin(9600);  // Starts the serial communication

  myServo.attach(servoPin);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  digitalWrite(ledPin,HIGH);
  delay(25);
  digitalWrite(ledPin,LOW);
  delay(25);
  digitalWrite(ledPin,HIGH);
  // Read the switch state to determine max safety distance
  int state = digitalRead(switchPin);
  if (state == 0){
    maxSafetyDistance = 20;
  } else {
    maxSafetyDistance = 40;
  }

  for (int angle = 0; angle <= 180; angle++)
   {
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    safetyDistance = distance;
    myServo.write(angle);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    delay(1);
    int moistureLevel = analogRead(moisturePin);
    if(moistureLevel<800)
    { 
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      int moistureLevel = analogRead(moisturePin);
    }
    if (safetyDistance <= maxSafetyDistance) 
   {   if (angle>=90)
       {
      digitalWrite(vibro, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(25* safetyDistance); 
      digitalWrite(buzzer, LOW);
      digitalWrite(vibro, LOW);
       }
      
      else
      {
      digitalWrite(buzzer, HIGH);
      delay(25* safetyDistance); 
      digitalWrite(buzzer, LOW);
      delay(10);
      }
    
  } 
    else 
    {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
     }
    // Wait for 25 milliseconds
  }
  digitalWrite(ledPin,HIGH);
  for(int angle = 180 ; angle >=0;angle--)
  {
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    int state = digitalRead(switchPin);
    

    if (state == 0){
    maxSafetyDistance = 20;
     }
    else {
    maxSafetyDistance = 40;
    }

   

    safetyDistance = distance;
    myServo.write(angle);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
 
    int moistureLevel = analogRead(moisturePin);
    if(moistureLevel<800)
    { 
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      int moistureLevel = analogRead(moisturePin);
    }
    if (safetyDistance <= maxSafetyDistance)
   {
    if (angle>=90)
       {
      digitalWrite(vibro, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(25* safetyDistance); 
      digitalWrite(buzzer, LOW);
      digitalWrite(vibro, LOW);
       }
      
      else
      {
      digitalWrite(buzzer, HIGH);
      delay(25* safetyDistance); 
      digitalWrite(buzzer, LOW);
      delay(10);
      }
 
      
    } 
    else
    {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
    }
    // Wait for 25 milliseconds
  }



}

  // Move servo from 180 to 0 degrees
 

