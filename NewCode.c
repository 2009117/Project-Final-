const int LEDPin= 13; //Set LED on 13 pin
const int PIRPin= 2;  // Set Movement Sensor on pin 2
int switchPin = 12; //set Switch on 12 pin
int switchState;    // Value of Switch

#define NOTE_C4  262 // note of buzzer
#define NOTE_G3  196 // second note of buzzer

int melody[] = {    //sequence of the notes Notes 
  NOTE_C4, NOTE_G3,NOTE_C4, NOTE_G3,NOTE_C4, NOTE_G3,NOTE_C4, NOTE_G3,
};

int noteDurations[] = // note durations: 4 = quarter note
{
  4, 4, 4, 4, 4, 4, 4, 4
};

void setup()
{
  pinMode(LEDPin, OUTPUT);   //Initialize LED as output
  pinMode(PIRPin, INPUT);    //initialize the Movement Sensor as input
  pinMode(switchPin, INPUT); //initialize the Switch as input
}

void loop()
{
  int value= digitalRead(PIRPin); //read the state of the Movement Sensor value
 
switchState = digitalRead(switchPin);//read the state of the switch value

if (switchState == 1) // When the Switch is enable
{
  
  if (value == HIGH) // When the Movement Sensor is active
  {
    digitalWrite(LEDPin, HIGH); //delay to turn on
    delay(10);
    digitalWrite(LEDPin, LOW);  //delay to turn off
    delay(50);
    digitalWrite(LEDPin,HIGH);  //stay turned on after delay

    for (int thisNote = 0; thisNote < 8; thisNote++) { 
    
    int noteDuration = 1000 / noteDurations[thisNote];// i´ts to calculate the note duration, taking one second divided by the note type.
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;// to distinguish the notes, seting a minimum time between them.
    delay(pauseBetweenNotes);
    noTone(8);// stop the tone playing:
  }  
  } 
  else
  {
    digitalWrite(LEDPin, LOW); 
  }
}
}
