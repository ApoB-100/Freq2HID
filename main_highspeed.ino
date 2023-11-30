#include <Keyboard.h>

// Checks only for input volume, no FFT calculation to filter a specific frequency
// Evaluated with AD MAX4466 mic preamp and ATSAMD21G18 M0+ SoC with integrated ADC

const int threshold = 200;

void setup() {
  Serial.begin(115200);
  Keyboard.begin();

  // Board dependent, optional setting
  // Select lowest resolution to reduce conversion time
  // see MT SAMD21 datasheet for further reference, chapter 33.6.1, DS40001882H-page 783
  analogReadResolution(8);
}

void loop() {
  int volume = analogRead(A0);

  // DEBUG
  // Serial.println(volume);
  
  if (volume > threshold) {
    Keyboard.press(KEY_SPACE);
    delay(100);
    Keyboard.release(KEY_SPACE);
    Serial.println(volume);
    delay(1500);
  }
}
  
