#include <Keyboard.h>

// Checks only for input volume, no FFT calculation

const int threshold = 600;

void setup() {
  Serial.begin(115200);
  Keyboard.begin();

  // Board dependent, optioal setting
  analogReadResolution(12);
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
  
