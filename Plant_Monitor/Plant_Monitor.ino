

#include <LedControl.h> // including a library lets you use pre-written code in your project

int sensorPin = A0; // select the input pin for the Soil Moisture Sensor
int sensorValue = 0; // variable to store the value coming from the sensor

const int DIN_PIN = 9; //the pin we connect to the LEDs Digital In (DIN) pin
const int CS_PIN = 8; //the pin we connect to the LEDs Chip Select (CS) pin
const int CLK_PIN = 7; //the pin we connect to the LEDs Clock (CLK) pin

LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);

void setup() {
  // set the sensor pin as an input
  pinMode(sensorPin, INPUT);
  
  // settings for the LED matrix to display properly
  display.shutdown(0, false);
  // Set brightness to a medium value
  display.setIntensity(0, 8);
  // Clear the display
  display.clearDisplay(0);

  // starting the serial monitor so that we can send information there
  Serial.begin(9600);
}

void loop() {
  // change sensorValue to equal what we read from the sensor 
  sensorValue = analogRead(sensorPin);

  //print the value to the seial monitor
  Serial.println(sensorValue);
  // sensorValue are between 0 and 350 when using 3.3V pin

//if statements check the value then display the appropriate "face"

//sensor reads higher than 200
  if (sensorValue > 200) {
    drawShocked();
    Serial.println("water high");
  }
//sensor reads less than or equal to 200 AND greater than 100
  if (sensorValue <= 200 && sensorValue > 100) {
    drawHappy();
    Serial.println("water good");
  }
//sensor reads less than or equal to 100 AND greater than or equal to 0
  if (sensorValue <= 100 && sensorValue >= 0) {
    drawSad();
    Serial.println("water low");
  }
  // stop the program for X milliseconds:
  delay(1000);
}

void drawHappy() {
  //use binary to set each row's configuration of LEDs 0 = off, 1 = on.
  display.setRow(0, 0, B00000000);
  display.setRow(0, 1, B00110110);
  display.setRow(0, 2, B01000110);
  display.setRow(0, 3, B01000000);
  display.setRow(0, 4, B01000000);
  display.setRow(0, 5, B01000110);
  display.setRow(0, 6, B00110110);
  display.setRow(0, 7, B00000000);
}

void drawSad() {
  //use binary to set each row's configuration of LEDs 0 = off, 1 = on.
  display.setRow(0, 0, B00000000);
  display.setRow(0, 1, B01100110);
  display.setRow(0, 2, B00010110);
  display.setRow(0, 3, B00010000);
  display.setRow(0, 4, B00010000);
  display.setRow(0, 5, B00010110);
  display.setRow(0, 6, B01100110);
  display.setRow(0, 7, B00000000);
}

void drawShocked() {
    //use binary to set each row's configuration of LEDs 0 = off, 1 = on.
  display.setRow(0, 0, B00000000);
  display.setRow(0, 1, B00000110);
  display.setRow(0, 2, B01110110);
  display.setRow(0, 3, B01110000);
  display.setRow(0, 4, B01110000);
  display.setRow(0, 5, B01110110);
  display.setRow(0, 6, B00000110);
  display.setRow(0, 7, B00000000);
}
