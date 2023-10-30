const int pingPin = 12; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 8; // Echo Pin of Ultrasonic Sensor

const int redpin1 = 11; // select the pin for the red LED
const int bluepin1 =10; // select the pin for the  blue LED
const int greenpin1 =9; // select the pin for the green LED

const int redpin2 = 7; // select the pin for the red LED
const int bluepin2 = 6; // select the pin for the  blue LED
const int greenpin2 = 5; // select the pin for the green LED

const int redpin3 = 4; // select the pin for the red LED
const int bluepin3 = 3; // select the pin for the  blue LED
const int greenpin3 = 2; // select the pin for the green LED

int ourPin = 1;

int val;
int interval;
int i;

void setup() {
  pinMode(redpin1, OUTPUT);
  pinMode(bluepin1, OUTPUT);
  pinMode(greenpin1, OUTPUT);

  pinMode(redpin2, OUTPUT);
  pinMode(bluepin2, OUTPUT);
  pinMode(greenpin2, OUTPUT);

  pinMode(redpin3, OUTPUT);
  pinMode(bluepin3, OUTPUT);
  pinMode(greenpin3, OUTPUT);

  pinMode(ourPin, OUTPUT);

  Serial.begin(9600);
}

void lightsFlicker(int interval) {

  tone(ourPin, 23 * interval);

  for(val = 255; val > 0; val--)
  {
    //tone(soundPin, 23 * interval), interval * 2;
    analogWrite(11, val);
    analogWrite(10, 255 - val);
    analogWrite(9, 128 - val);

    analogWrite(7, val);
    analogWrite(6, 255 - val);
    analogWrite(5, 128 - val);

    analogWrite(4, val);
    analogWrite(3, 255 - val);
    analogWrite(2, 128 - val);

    delay(interval * 2); 
  }


  for (i = interval; i > 0; i--) {
    analogWrite(11, 0);
    analogWrite(10, 0);
    analogWrite(9, 0);

    analogWrite(7, 0);
    analogWrite(6, 0);
    analogWrite(5, 0);

    analogWrite(4, 0);
    analogWrite(3, 0);
    analogWrite(2, 0);

    delay(100);

    analogWrite(11, 255);
    analogWrite(10, 255);
    analogWrite(9, 255);

    analogWrite(7, 255);
    analogWrite(6, 255);
    analogWrite(5, 255);

    analogWrite(4, 255);
    analogWrite(3, 255);
    analogWrite(2, 255);

     delay(100);
  }
    

  for(val = 0; val < 255; val++)
  {
    //tone(soundPin, 23 * interval, interval * 2);
    analogWrite(11, val);
    analogWrite(10, 255 - val);
    analogWrite(9, 128 - val);

    analogWrite(7, val);
    analogWrite(6, 255 - val);
    analogWrite(5, 128 - val);

    analogWrite(4, val);
    analogWrite(3, 255 - val);
    analogWrite(2, 128 - val);
    
    delay(interval * 2); 
  }
}

void loop() {

  long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);

   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);

   delay(50);

  analogWrite(11, 0);
  analogWrite(10, 255);
  analogWrite(9, 255);

  analogWrite(7, 0);
  analogWrite(6, 255);
  analogWrite(5, 255);

  analogWrite(4, 0);
  analogWrite(3, 255);
  analogWrite(2, 255);

  if (inches < 1) {
    tone(ourPin, 440);
    lightsFlicker(1);
  }
  if (inches < 2) {
    tone(ourPin, 440);
    lightsFlicker(2);
  }
  if (inches < 3) {
    tone(ourPin, 440);
    lightsFlicker(3);
  }
  if (inches < 4) {
    tone(ourPin, 440);
    lightsFlicker(4);
  }
  if (inches < 5) {
    tone(ourPin, 440);
    lightsFlicker(5);
  }
}
  
  long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

  long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
} 


