const int WAIT = 100;
const int LIGHT = 11;
const int BEEPER = 9;

void setup(){
    pinMode( BEEPER, OUTPUT );
    pinMode( LIGHT, OUTPUT );
    Serial.begin(9600);
}

void loop(){
    int i;
    i = 0;

    while ( i <= 255 ){
        analogWrite( LIGHT, i );
        delay( WAIT );
        i = i + 5;
    }

    

    tone(BEEPER, 440, 100);

    i = 255;
    while ( i >= 0 ){
        analogWrite( LIGHT, i );
        delay( WAIT );
        i = i - 5;
    }

    
    tone(BEEPER, 440, 100); 
    
}