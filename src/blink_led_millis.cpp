#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define RGB_PIN 38

const int LED_PIN = 2;
const unsigned long interval = 5000;
unsigned long previousMillis = 0;
int ledState = LOW;
int rgbState = LOW;

Adafruit_NeoPixel pixel(1, RGB_PIN, NEO_GRB + NEO_KHZ800);

void toggleLedState()
{
    if (ledState == LOW)
    {
        ledState = HIGH;
    }
    else
    {
        ledState = LOW;
    }
    Serial.println('toggling led state...');
    digitalWrite(LED_PIN, ledState);
}

void turnOnRgb()
{
    Serial.println('turning on rgb...');
    pixel.setPixelColor(0, pixel.Color(0, 255, 0));
    pixel.show();
}

void turnOffRgb()
{
    Serial.println('turning off rgb...');
    pixel.clear();
    pixel.show();
}

void toggleRgbState()
{
    if (rgbState == LOW)
    {
        rgbState = HIGH;
        turnOnRgb();
    }
    else
    {
        rgbState = LOW;
        turnOffRgb();
    }
}

bool poll(unsigned long currentMillis)
{
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        toggleRgbState();
        toggleLedState();
        return true;
    }
    return false;
}

void setup()
{
    Serial.begin(115200);
    Serial.println("hello world...");
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    poll(millis());
}