#include "rgb_lcd.h"

rgb_lcd lcd;

const int laserPin = 2;  // Replace with the actual pin number connected to the range finder

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  pinMode(laserPin, OUTPUT);
  digitalWrite(laserPin, LOW);
  // set microseconds to at least 2
  delayMicroseconds(2);
  digitalWrite(laserPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(laserPin, LOW);

  pinMode(laserPin, INPUT);
  long pulse = pulseIn(laserPin, HIGH);

  Serial.print("Pulse Width: ");
  //lcd.print("Pulse: " + pulse + " ms");
  lcd.write("Pulse: ");
  lcd.print(pulse);
  lcd.write(" ms");
  Serial.print((float)pulse);
  Serial.println(" ms");
  delay(1000); 
  lcd.clear();
}