#include <Servo.h>
#include "pitches.h"

const int buzzerPin = 3;
const int buttonPin = 13;     // the number of the pushbutton pin
const int ledred = 6;
const int ledgreen = 7;
const int ledblue = 8;

Servo myServo1; //door spinner
Servo myServo3; //iconic face
int buttonState = 0;

// notes in the melody:
// use 0 for a rest
// put each measure on its own line
int melody[] = {
  NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_E5,
  NOTE_C5, NOTE_D5, NOTE_C5,
  NOTE_C5, NOTE_B4, 
  NOTE_B4, NOTE_D4, NOTE_E4,
  NOTE_F4, NOTE_D5,
  NOTE_B4, NOTE_C5, NOTE_B4,
  NOTE_A4, NOTE_G4,
  NOTE_G4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_D5, NOTE_C5,
  NOTE_A4, NOTE_D5, NOTE_E5,
  NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_G4, NOTE_F5,
  NOTE_E5, NOTE_D5,
  NOTE_C5
  
};

// note durations: 1 = whole note, 4 = quarter note, 8 = eighth note, etc.:
// be sure each note or rest in the melody above has a corresponding duration below
// put each measure on its own line
int noteDurations[] = {
  4, 4,
  2, 2,
  2, 4, 4,
  2, 2,
  2, 4, 4,
  2, 2,
  2, 4, 4,
  2, 2,
  2, 4, 4,
  2, 4, 4,
  2, 4, 4,
  2, 4, 4,
  2, 4, 4,
  2, 2,
  2, 2,
  1
   
};

// set the tempo
// a tempo of 60 is one beat per second
// a tempo of 120 would be twice as fast
int beatsPerMinute = 60;

void setup() {
  // put your setup code here, to run once:
  myServo1.attach(10);
  myServo3.attach(12);
   // initialize the LED pin as an output:
  pinMode(ledgreen, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledblue, OUTPUT);

  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
  playSong(); 
  servoStuff();
  lightSequence();
  }
  if (buttonState == LOW) {
  
  }
}
void playSong() {
   // iterate over the notes of the melody:
  int len = sizeof(melody)/sizeof(melody[0]);
  for (int thisNote = 0; thisNote < len; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = static_cast<int>(1000 / noteDurations[thisNote] * 60 / beatsPerMinute);
    tone(buzzerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
  // Pause before playing again
  delay(1000);
}
void servoStuff() {
  myServo1.write(360);
  delay(1000);
  myServo1.write(0);
  delay(1000);
  myServo1.write(360);
  delay(1000);
  myServo1.write(0);
  delay(1000);
  myServo1.write(360);
  delay(1000);
  myServo1.write(0);
  delay(1000);
  myServo1.write(360);
  delay(1000);
  myServo1.write(0);
  delay(1000);
  myServo3.write(90);
  delay(1000);
  myServo3.write(0);
  delay(1000);
  myServo3.write(90);
  delay(1000);
  myServo3.write(0);
  delay(1000);
  myServo3.write(90);
  delay(1000);
  myServo3.write(0);
  delay(1000);
  myServo3.write(90);
  delay(1000);
  myServo3.write(0);
  delay(1000);
}

void lightSequence() {
  digitalWrite(ledred, HIGH);
  delay(500);
  digitalWrite(ledgreen, HIGH);
  delay(500);
  digitalWrite(ledblue, HIGH);
  delay(500);
  digitalWrite(ledblue, LOW);
  digitalWrite(ledgreen, LOW);
  digitalWrite(ledred, LOW);
  delay(500);
  digitalWrite(ledblue, HIGH);
  delay(250);
  digitalWrite(ledblue, LOW);
  digitalWrite(ledgreen, HIGH);
  delay(250);
  digitalWrite(ledgreen, LOW);
  digitalWrite(ledred, HIGH);
  delay(250);
  digitalWrite(ledred, LOW);
  delay(250);
  digitalWrite(ledgreen, HIGH);
  digitalWrite(ledred, HIGH);
  digitalWrite(ledblue, HIGH);
  delay(500);
  digitalWrite(ledgreen, HIGH);
  digitalWrite(ledred, HIGH);
  digitalWrite(ledblue, HIGH);
  delay(500);
  digitalWrite(ledgreen, LOW);
  digitalWrite(ledred, LOW);
  digitalWrite(ledblue, LOW);
  
  
  
}
