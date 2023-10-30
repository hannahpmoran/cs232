// wiring instructions for a kindergardener
// connect the + wire to any of the V voltage pins on the digital read of the arduino
// connect the R to the S pin on the arduino at cooresponding pin below
// repeat for G and B

const int redpin1 = 11; // select the pin for the red LED
const int bluepin1 =10; // select the pin for the  blue LED
const int greenpin1 =9; // select the pin for the green LED

const int redpin2 = 7; // select the pin for the red LED
const int bluepin2 = 6; // select the pin for the  blue LED
const int greenpin2 = 5; // select the pin for the green LED

const int redpin3 = 4; // select the pin for the red LED
const int bluepin3 = 3; // select the pin for the  blue LED
const int greenpin3 = 2; // select the pin for the green LED

int val;

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

  Serial.begin(9600);
}
void loop() {
  for(val = 255; val > 0; val--)
  {
    analogWrite(11, val);
    analogWrite(10, 255 - val);
    analogWrite(9, 128 - val);
    Serial.println(val, DEC);
    delay(5); 
  }
  for(val = 0; val < 255; val++)
  {
    analogWrite(11, val);
    analogWrite(10, 255 - val);
    analogWrite(9, 128 - val);
    
    Serial.println(val, DEC);
    delay(5); 
  }

  analogWrite(11, 0);
  analogWrite(10, 0);
  analogWrite(9, 0);

  
}