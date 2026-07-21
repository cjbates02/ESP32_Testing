#include <Arduino.h>

const int INPUT_PIN = 2;

// using INPUT_PULLUP sets the default state of the pin toe HIGH - so the pin does not pick up random electrical signals. hence the name "PULLUP" as the power supply is pulling the state of the pin to HIGH.

bool lastState = HIGH;

void setup()
{
    Serial.begin(115200);
    pinMode(INPUT_PIN, INPUT_PULLUP);
    Serial.println("setup complete. v2");
}

void loop()
{
    bool currentState = digitalRead(INPUT_PIN);
    Serial.println(currentState);
    if (currentState == LOW && lastState == HIGH) {
        Serial.println("button pressed. v2.");
    }
    lastState = currentState;
    delay(200);
}