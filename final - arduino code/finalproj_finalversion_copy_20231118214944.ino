#include <Wire.h>
#include <hd44780.h>                       
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

const int LCD_COLS = 20;
const int LCD_ROWS = 4;

static const uint8_t PIN_MP3_TX = 11;
static const uint8_t PIN_MP3_RX = 10;

const int RED_PIN = 9;
const int GREEN_PIN = 8;
const int BLUE_PIN = 7;

hd44780_I2Cexp lcd; 
int status;

// int fortuneInt = 0;

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
DFRobotDFPlayerMini player;

void setup() {

  randomSeed(analogRead(9));

  // serial setup
  Serial.begin(9600);
  softwareSerial.begin(9600);

  // LCD setup
  lcd.begin(20,4); 

  // LCD backlight setup
  lcd.backlight();

  // LED setup
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);


  // set robo face asleep at startup/may change to be completely off
  lcd.clear();
  lcd.print("|   _          _   |");
  lcd.setCursor(0,2); // set cursor at line 3 char 0.
  lcd.print("         --         ");
  delay(1000);

  // MP3 on checker
  if (player.begin(softwareSerial)) {
    Serial.println("OK");
  } else {
    Serial.println("FAIL!");
  }

  // Volume setter: Range 0-30
  player.volume(30); 

}

// -------------------------------------- STARTUP ANIMATION --------------------------------------
int startup() {

  // LCD clear check
  lcd.clear();

  // flashes to display wake up
  for(int i = 0; i< 3; i++)
  { 
    lcd.backlight();
    lcd.clear();
    analogWrite(RED_PIN, 255);
    analogWrite(BLUE_PIN, 255);
    analogWrite(GREEN_PIN, 255);
    delay(250);

    analogWrite(RED_PIN, 0);
    analogWrite(BLUE_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    lcd.noBacklight();
    delay(250);
  }

  // set face
  lcd.backlight();
  lcd.clear();
  lcd.print("|   _          _   |");
  lcd.setCursor(0,2); // set cursor at line 3 char 0.
  lcd.print("         --         ");
  delay(1000);

  return 1;
}

// -------------------------------------- SHUT-DOWN ANIMATION --------------------------------------
int shutDown() {
  
  // LEDs
  analogWrite(RED_PIN, 255);
  analogWrite(BLUE_PIN, 0);
  analogWrite(GREEN_PIN, 255);

  lcd.clear();
  lcd.print("|   v          v   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(250);
  
  lcd.clear();
  lcd.print("|   _          _   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(1000);

  return 1;
}

// -------------------------------------- WAKE UP ANIMATION --------------------------------------
int wakeUp() {

  // LEDs
  analogWrite(RED_PIN, 255);
  analogWrite(BLUE_PIN, 255);
  analogWrite(GREEN_PIN, 0);

  // waking up blink animation
  lcd.clear();
  lcd.print("|   v          v   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(250);

  lcd.clear();
  lcd.print("|   O          O   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(1000);

  lcd.clear();
  lcd.print("|   v          v   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(250);

  lcd.clear();
  lcd.print("| < O          O > |");
  lcd.setCursor(0,2);
  lcd.print("         --         ");
  delay(1000);

  lcd.clear();
  lcd.print("|   O          O   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(2000);

  return 1;
}

// -------------------------------------- HAPPY ANIMATION --------------------------------------
int happyRobo() {
  lcd.clear();
  lcd.print("|   v          v   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(250);

  lcd.clear();
  lcd.print("|   O          O   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(1000);

  lcd.clear();
  lcd.print("|   v          v   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(250);

  lcd.clear();
  lcd.print("| < O          O > |");
  lcd.setCursor(0,2);
  lcd.print("         --         ");
  delay(1000);

  lcd.clear();
  lcd.print("|   ^          ^   |");
  lcd.setCursor(0,2); 
  lcd.print("    *    --    *    ");
  delay(2000);

  return 1;
}

// -------------------------------------- BLINKING ANIMATION --------------------------------------
int blinkingRobo() {
  lcd.clear();
  lcd.print("|   v          v   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(250);

  lcd.clear();
  lcd.print("|   O          O   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(1000);

  lcd.clear();
  lcd.print("|   v          v   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(250);

  lcd.clear();
  lcd.print("|   O          O   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(2000);

  return 1;
}

// -------------------------------------- DISINTERESTED ANIMATION --------------------------------------
int disinterestedRobo() {
  lcd.clear();
  lcd.print("|   v          v   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(250);

  lcd.clear();
  lcd.print("|   >          >   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(1000);

  lcd.clear();
  lcd.print("|   v          v   |");
  lcd.setCursor(0,2); 
  lcd.print("         --         ");
  delay(250);

  lcd.clear();
  lcd.print("|   =          =   |");
  lcd.setCursor(0,2); 
  lcd.print("     )   --   (     ");
  delay(250);

  return 1; 
}

// -------------------------------------- FIRST DIALOGUE --------------------------------------
int firstDialogue() {
  int noSwitch = analogRead(A2);
  int yesSwitch = analogRead(A3);

  // NO is A2
  // YES is A3

  player.play(01);
  blinkingRobo();
  delay(9 * 1000);

  while((digitalRead(A2) == HIGH) && (digitalRead(A3) == HIGH)) {
    
    delay(250);

    if (digitalRead(A2) == LOW) 
    {

      Serial.println("Made it here -- no");
      analogWrite(RED_PIN, 0);
      analogWrite(BLUE_PIN, 255);
      analogWrite(GREEN_PIN, 255);

      return 0;
    }

    if (digitalRead(A3) == LOW) 
    {

      Serial.println("Made it here");
      analogWrite(RED_PIN, 255);
      analogWrite(BLUE_PIN, 255);
      analogWrite(GREEN_PIN, 0);

    }
  }
  return 1;
}

// -------------------------------------- SECOND DIALOGUE --------------------------------------
int secondDialogue() {

  player.play(05);
  blinkingRobo();

  delay(16 * 1000);

  while((digitalRead(A2) == HIGH) && (digitalRead(A3) == HIGH)) {
   
    delay(250);

    if (digitalRead(A2) == LOW) 
    {

      Serial.println("Made it here -- no");
      analogWrite(RED_PIN, 0);
      analogWrite(BLUE_PIN, 255);
      analogWrite(GREEN_PIN, 255);

      player.play(9);
      disinterestedRobo();
      delay(24 * 1000);

      return 1;
    }

    if (digitalRead(A3) == LOW) 
    {

      Serial.println("Made it here -- yes");
      analogWrite(RED_PIN, 0);
      analogWrite(BLUE_PIN, 0);
      analogWrite(GREEN_PIN, 255);

      player.play(07);
      happyRobo();
      delay(21 * 1000);

      return 1;
    }
  }

  return 1;
}
// -------------------------------------- THIRD DIALOGUE --------------------------------------
int thirdDialogue() {

  player.play(11);
  blinkingRobo();
  delay(6 * 1000);

  while((digitalRead(A2) == HIGH) && (digitalRead(A3) == HIGH)) {
    
    delay(250);

    if (digitalRead(A2) == LOW) 
    {

      Serial.println("Made it here -- no");
      analogWrite(RED_PIN, 0);
      analogWrite(BLUE_PIN, 255);
      analogWrite(GREEN_PIN, 0);

      player.play(15);
      happyRobo();
      delay(10 * 1000);

      return 1;
    }

    if (digitalRead(A3) == LOW) 
    {

      Serial.println("Made it here -- yes");
      analogWrite(RED_PIN, 255);
      analogWrite(BLUE_PIN, 0);
      analogWrite(GREEN_PIN, 255);

      player.play(13);
      blinkingRobo();
      delay(12 * 1000);

      return 1;
    }

  }


  return 1;
}

// -------------------------------------- FOURTH DIALOGUE --------------------------------------
int fourthDialogue() {

  player.play(17);
  blinkingRobo();
  delay(12 * 1000);

  while((digitalRead(A2) == HIGH) && (digitalRead(A3) == HIGH)) {
    
    delay(250);

    if (digitalRead(A2) == LOW) 
    {

      player.play(21);
      disinterestedRobo();
      delay(13 * 1000);

      Serial.println("Made it here -- no");
      analogWrite(RED_PIN, 0);
      analogWrite(BLUE_PIN, 255);
      analogWrite(GREEN_PIN, 255);

      return 1;
    }

    if (digitalRead(A3) == LOW) 
    {
      Serial.println("Made it here -- yes");
      analogWrite(RED_PIN, 255);
      analogWrite(BLUE_PIN, 255);
      analogWrite(GREEN_PIN, 0);

      player.play(19);
      delay(24 * 1000);

      return 1;
    }
  }

  return 1;
}

// -------------------------------------- FIFTH DIALOGUE --------------------------------------
int fifthDialogue() {

  player.play(23);
  blinkingRobo();
  delay(5 * 1000);

  while((digitalRead(A2) == HIGH) && (digitalRead(A3) == HIGH)) {
    
    delay(250);

    if (digitalRead(A2) == LOW) 
    {

      Serial.println("Made it here -- no");
      analogWrite(RED_PIN, 0);
      analogWrite(BLUE_PIN, 0);
      analogWrite(GREEN_PIN, 255);

      player.play(27);
      happyRobo();
      delay(26 * 1000);

      return 1;
    }

    if (digitalRead(A3) == LOW) 
    {
      Serial.println("Made it here -- yes");
      analogWrite(RED_PIN, 255);
      analogWrite(BLUE_PIN, 255);
      analogWrite(GREEN_PIN, 0);

      player.play(25);
      blinkingRobo();
      delay(29 * 1000);

      return 1;
    }
  }

  return 1;
}

// -------------------------------------- FORTUNE DIALOGUE --------------------------------------
int fortune() {

  int fortuneInt = random(8);
  Serial.println(fortuneInt);

  analogWrite(RED_PIN, 255);
  analogWrite(BLUE_PIN, 0);
  analogWrite(GREEN_PIN, 255);

  delay(500);
  player.play(29);
  happyRobo();
  blinkingRobo();
  delay(24 * 1000);

  if (fortuneInt == 0) 
  {
    player.play(31);
    delay(11 * 1000);
  }
  if (fortuneInt == 1) 
  {
    player.play(33);
    delay(12 * 1000);
  }
  if (fortuneInt == 2) 
  {
    player.play(35);
    delay(13 * 1000);
  }
  if (fortuneInt == 3) 
  {
    player.play(37);
    delay(13 * 1000);
  }
  if (fortuneInt == 4) 
  {
    player.play(39);
    delay(15 * 1000);
  }
  if (fortuneInt == 5) 
  {
    player.play(41);
    delay(12 * 1000);
  }
  if (fortuneInt == 6) 
  {
    player.play(43);
    delay(12 * 1000);
  }
  if (fortuneInt == 7) 
  {
    player.play(45);
    delay(13 * 1000);
  }

  player.play(47);
  delay(13 * 1000);
  return 1;

}

// -------------------------------------- MAIN LOOP --------------------------------------
void loop() {

  // button testing
  int offValue = analogRead(A0);
  int onValue = analogRead(A1);
  int noSwitch = analogRead(A2);
  int yesSwitch = analogRead(A3);

  // int fort = random(8);
  // Serial.println(fort);

  // OFF SWITCH
  if (offValue == 0) 
  {
    lcd.clear();
    shutDown();
  }

  // ON SWITCH
  if (onValue == 0) 
  {
    startup();
    wakeUp();

    if (firstDialogue() == 0) 
    {
    player.play(03);
    delay(4 * 1000);
    } 
      
      else 
      {
        secondDialogue();

        thirdDialogue();

        fourthDialogue();

        fifthDialogue();

        fortune();
      }
    }
  }

  

