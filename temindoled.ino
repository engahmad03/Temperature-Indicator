#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display object declaration
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// Pin assignments for LEDs
const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;
const int ledPin5 = 6;
const int ledPin6 = 7;
const int ledPin7 = 8;
const int ledPin8 = 9;

// Pin assignment for LM35 sensor
const int lm35Pin = A0;

void setup() {
  // Initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  
  // Set LED pins as output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  
  // Initialize Serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the LM35 sensor
  int sensorValue = analogRead(lm35Pin);
  
  // Convert the sensor value to temperature in degrees Celsius
  float temperature = (sensorValue * 5.0 / 1024.0) * 100.0;
  
  // Print the temperature to Serial monitor (optional)
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  // Display temperature on OLED
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");
  display.display();
  
  // Turn on/off LEDs based on temperature
  if (temperature >= 20) {
    digitalWrite(ledPin1, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
  }
  
  if (temperature >= 25) {
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
  }
  
  if (temperature >= 30) {
    digitalWrite(ledPin3, HIGH);
  } else {
    digitalWrite(ledPin3, LOW);
  }
  
  if (temperature >= 35) {
    digitalWrite(ledPin4, HIGH);
  } else {
    digitalWrite(ledPin4, LOW);
  }
  
  if (temperature >= 40) {
    digitalWrite(ledPin5, HIGH);
  } else {
    digitalWrite(ledPin5, LOW);
  }
  
  if (temperature >= 45) {
    digitalWrite(ledPin6, HIGH);
  } else {
    digitalWrite(ledPin6, LOW);
  }
  
  if (temperature >= 50) {
    digitalWrite(ledPin7, HIGH);
  } else {
    digitalWrite(ledPin7, LOW);
  }
  
  if (temperature >= 55) {
    digitalWrite(ledPin8, HIGH);
  } else {
    digitalWrite(ledPin8, LOW);
  }
  
  // Delay before the next temperature reading
  delay(500);
}
