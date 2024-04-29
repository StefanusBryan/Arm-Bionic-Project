#include <Servo.h>

Servo myservo1;  // create servo object to control a servo for SG90
Servo myservo2;  // create servo object to control a servo for SG90
Servo myservo3;  // create servo object to control a servo for SG90
Servo myservo4;  // create servo object to control a servo for SG90
int trigPin = 2;  // Ultrasonic sensor trig pin
int echoPin = 3;  // Ultrasonic sensor echo pin
int distanceThreshold = 10; // Threshold distance in cm

void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object for SG90
  myservo2.attach(10); // attaches the servo on pin 10 to the servo object for SG90
  myservo3.attach(11); // attaches the servo on pin 11 to the servo object for SG90
  myservo4.attach(12); // attaches the servo on pin 12 to the servo object for SG90
  Serial.begin(9600); // starts the serial communication
  pinMode(trigPin, OUTPUT);  // sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // sets the echoPin as an Input
}

void loop() {
  long duration;
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance >= distanceThreshold && myservo1.read() == 120 && myservo2.read() == 120 && myservo3.read() == 120 && myservo4.read() == 120) {
    myservo1.write(60);
    myservo2.write(60);
    myservo3.write(60);
    myservo4.write(60);
    delay(2000);
  } else if (distance >= distanceThreshold && myservo1.read() == 150 && myservo2.read() == 150 && myservo3.read() == 150 && myservo4.read() == 90) {
    myservo1.write(0);
    myservo2.write(0);
    myservo3.write(0);
    myservo4.write(60);
    delay(2000);
  } else if (distance >= distanceThreshold && myservo1.read() == 180 && myservo2.read() == 180 && myservo3.read() == 120 && myservo4.read() == 90) { //Ballpoint
    myservo1.write(90);
    myservo2.write(90);
    myservo3.write(0);
    myservo4.write(60);
    delay(2000);
  } else if (distance >= distanceThreshold && myservo1.read() == 180 && myservo2.read() == 100 && myservo3.read() == 100 && myservo4.read() == 150) { //Key
    myservo1.write(90);
    myservo2.write(0);
    myservo3.write(0);
    myservo4.write(60);
    delay(2000);
  } 
  
  
  else if (distance < distanceThreshold && myservo1.read() == 60 && myservo2.read() == 60 && myservo3.read() == 60 && myservo4.read() == 60) {
    myservo1.write(120);
    myservo2.write(120);
    myservo3.write(120);
    myservo4.write(120);
    delay(2000);
  } else if (distance < distanceThreshold && myservo1.read() == 0 && myservo2.read() == 0 && myservo3.read() == 0 && myservo4.read() == 60) {
    myservo1.write(150);
    myservo2.write(150);
    myservo3.write(150);
    myservo4.write(90);
    delay(2000);
  } else if (distance < distanceThreshold && myservo1.read() == 90 && myservo2.read() == 90 && myservo3.read() == 0 && myservo4.read() == 60) { //Ballpoint
    myservo1.write(180);
    myservo2.write(180);
    myservo3.write(120);
    myservo4.write(90);
    delay(2000);
  } else if (distance < distanceThreshold && myservo1.read() == 90 && myservo2.read() == 0 && myservo3.read() == 0 && myservo4.read() == 60) { //Key
    myservo1.write(180);
    myservo2.write(100);
    myservo3.write(100);
    myservo4.write(150);
    delay(2000);
  } 
  
  else {
    while (Serial.available()) {
      int pos1 = Serial.parseInt(); // read the incoming number for SG90
      int pos2 = Serial.parseInt(); // read the incoming number for SG90
      int pos3 = Serial.parseInt(); // read the incoming number for SG90
      int pos4 = Serial.parseInt(); // read the incoming number for SG90
      myservo1.write(pos1); // tell servo to go to position in variable 'pos1'
      myservo2.write(pos2); // tell servo to go to position in variable 'pos2'
      myservo3.write(pos3); // tell servo to go to position in variable 'pos3'
      myservo4.write(pos4); // tell servo to go to position in variable 'pos4'
    }
  }
}
