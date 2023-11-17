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

PulseOximeter pox;

uint32_t tsLastReport = 0;

void onBeatDetected()
{
    Serial.println("Beat!");
}

void setup()
{
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
}