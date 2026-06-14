#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// Blinks the built in RGP light on the ESP32 board.

#define RGB_PIN 38

Adafruit_NeoPixel pixel(1, RGB_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(115200);
  pixel.begin();
  pixel.clear();
  pixel.show();
  Serial.println("testing the light.");
}

void loop()
{
  pixel.setPixelColor(0, pixel.Color(255, 0, 0));
  pixel.show();
  delay(1000);

  pixel.setPixelColor(0, pixel.Color(0, 255, 0));
  pixel.show();
  delay(1000);

  pixel.setPixelColor(0, pixel.Color(0, 0, 255));
  pixel.show();
  delay(1000);

  pixel.clear();
  pixel.show();
  Serial.println("turning off the led.");
  delay(1000);
}