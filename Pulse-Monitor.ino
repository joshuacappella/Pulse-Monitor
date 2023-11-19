/*
 * 11/30/2023
 * Joshua Cappella Josiah Harvey
 * Final Project for EGCP-2120
 * Wrist-mounted monitor for tracking heart rate
 */

#include <Wire.h>
//might be worth considering rewriting some of the MAX30100 library functionality
//this would increase lines of code written, but would allow us to learn
//more, and keep the project more our own
#include "MAX30100.h"

#include "MAX30100_PulseOximeter.h"

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

int speakerPin = 8; // Speaker connected to D8

PulseOximeter pox;

uint32_t tsLastReport = 0;

void onBeatDetected()
{
    Serial.println("Beat!");
}

void setup()
{
    pinMode(speakerPin, OUTPUT);	//Setup up speaker pin for output 
    Serial.begin(115200);

    if (!pox.begin()) {
        Serial.println("Failed to initialize pulse oximeter");
        for(;;);
    }

    pox.setOnBeatDetectedCallback(onBeatDetected);

    pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
}


void loop()
{
    pox.update();

    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        Serial.print("Heart rate:");
        Serial.print(pox.getHeartRate());
        Serial.print("bpm / SpO2:");
        Serial.print(pox.getSpO2());
        Serial.println("%");

        tsLastReport = millis();
    }
    playCrabRave();       //Recommended for low heart rate, call when lower limit crossed
    playShootingStars();  //Recommended for high heart rate, call when upper limit crossed
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

