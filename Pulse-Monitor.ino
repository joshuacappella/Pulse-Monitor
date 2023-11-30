/*
 * 11/30/2023
 * Joshua Cappella Josiah Harvey
 * Final Project for EGCP-2120
 * Wrist-mounted monitor for tracking heart rate
 */

//might be worth considering rewriting some of the MAX30100 library functionality
//this would increase lines of code written, but would allow us to learn
//more, and keep the project more our own

#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   

//  Variables
const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED = LED_BUILTIN;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
                               
#define REPORTING_PERIOD_MS     1000
#define NOTE_A5S 932.3
#define NOTE_A5  880.0
#define NOTE_G5  784.0
#define NOTE_F5  698.5
#define NOTE_E5  659.3
#define NOTE_D5  587.3
#define NOTE_C5  523.3
#define NOTE_B4  493.9
#define NOTE_A4  440.0
#define NOTE_E4  329.6
#define NOTE_D4S 311.1
#define NOTE_B3  246.9
#define NOTE_G3S 207.7 
#define NOTE_REST 0

PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"

int speakerPin = 8; // Speaker connected to D8

uint32_t tsLastReport = 0;


void setup()
{
    pinMode(speakerPin, OUTPUT);	//Setup up speaker pin for output 
    Serial.begin(115200);
    // Configure the PulseSensor object, by assigning our variables to it. 
    pulseSensor.analogInput(PulseWire);   
    pulseSensor.blinkOnPulse(LED);       //auto-magically blink Arduino's LED with heartbeat.
    pulseSensor.setThreshold(Threshold);   
  
    // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
     if (pulseSensor.begin()) {
      Serial.println("We created a pulseSenso r Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }



}


void loop()
{
    if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened".
      int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                                 // "myBPM" hold this BPM value now. 
       Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
       Serial.print("BPM: ");                        // Print phrase "BPM: " 
       Serial.println(myBPM);                        // Print the value inside of myBPM.
       if(myBPM < 70){
        playShootingStars();  //Recommended for high heart rate, call when upper limit crossed     
       }
       if(myBPM > 200){
        playCrabRave();       //Recommended for low heart rate, call when lower limit crossed
       } 
    }
  
    delay(20);                    // considered best practice in a simple sketch.

}

void playCrabRave() {
    // Define note frequencies and durations
    float crabRave[] = {NOTE_D5, NOTE_A5S, NOTE_G5, NOTE_G5, NOTE_D5, NOTE_D5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_D5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_C5, NOTE_C5, NOTE_E5, NOTE_E5, NOTE_F5};
int noteDurations[] = {187, 187, 187, 103, 187, 103, 187, 187, 103, 187, 103, 187, 187, 103, 187, 187, 187, 103, 187}; // in milliseconds, adjusted for 30ms playNote delay
    // Play song
    for (int i = 0; i < sizeof(crabRave) / sizeof(crabRave[0]); i++) {
      playNote(crabRave[i], noteDurations[i]);
      delay(10); // Add a small delay between notes
    }
}

void playShootingStars() {
    // Define note frequencies and durations
    float shootingStars[] = {NOTE_D4S, NOTE_REST, NOTE_D4S, NOTE_E4, NOTE_REST, NOTE_B3, NOTE_G3S};
    int noteDurations[] = {520, 120, 170, 295, 70, 170, 150}; // in milliseconds, adjusted for 30ms playNote delay

    // Play song
    for (int i = 0; i < sizeof(shootingStars) / sizeof(shootingStars[0]); i++) {
      playNote(shootingStars[i], noteDurations[i]);
      delay(30); // Add a small delay between notes
    }
}

void playNote(float noteFrequency, int duration) {
    tone(speakerPin, noteFrequency, duration);
    delay(duration + 30); // Add a small delay between notes (30)
    noTone(speakerPin);
}
