#include <Arduino.h>

const int LED_PIN = 2;

void setup()
{
    Serial.begin(115200);
    Serial.println("hello world...");
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    Serial.println("turning on light.");
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    Serial.println("turning off light.");
    digitalWrite(LED_PIN, LOW);
    delay(1000);
}