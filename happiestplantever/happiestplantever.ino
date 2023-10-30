#include <Servo.h>
Servo servo;
const int BUTTON = 3;
const int LIGHT0 = 4;
const int LIGHT1 = 8;
const int LIGHT2 = 9;
const int SERVO_PIN = 11;

void setup() {

  // servo read
  servo.attach(SERVO_PIN);

  // button for happiness
  pinMode(BUTTON, INPUT);

  // light read
  pinMode(LIGHT0, OUTPUT);
  pinMode(LIGHT1, OUTPUT);
  pinMode(LIGHT2, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // init
  int timeForLight = 0;

  // read button
  int value = digitalRead(3);

  servo.writeMicroseconds(1550);

  // happy lights!
  if (value == 0) {
    timeForLight = 10;
    while (timeForLight > 0) {
      servo.writeMicroseconds(1600);
      analogWrite( LIGHT0 , HIGH );
      delay(500);
      analogWrite( LIGHT2 , LOW );

      servo.writeMicroseconds(1650);
      analogWrite( LIGHT1 , HIGH );
      delay(500);
      analogWrite( LIGHT0 , LOW );
      
      servo.writeMicroseconds(1650);
      analogWrite( LIGHT2 , HIGH );
      delay(500);
      analogWrite( LIGHT1 , LOW );

      timeForLight = timeForLight - 1;
    }

    // reset all areas
    analogWrite( LIGHT0 , LOW );
    analogWrite( LIGHT1 , LOW );
    analogWrite( LIGHT2 , LOW );
    servo.writeMicroseconds(1550);
    timeForLight = 0;

  } 
  
}