#include <Keyboard.h>
#include <AudioFrequencyMeter.h>

AudioFrequencyMeter frequencyMeter;

const int buttonPin = 6;    // Pin number connected to the button
const int threshold = 500;  // Set your desired volume threshold here
bool keyboardActive = false;
unsigned long previousMillis = 0; // will store last time the volume was printed
const long interval = 500;        // interval at which to print volume (milliseconds)
const float targetFrequency = 500; // Target frequency
const float frequencyTolerance = 5; // Tolerance for frequency detection
unsigned long lastDebounceTime = 0; // will store last time the button was toggled
const long debounceDelay = 50;      // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set the button as an input with internal pull-up
  Serial.begin(115200);
  Keyboard.begin();
  frequencyMeter.begin(A0, 10000); // Initialize frequency meter
}

void loop() {
  unsigned long currentMillis = millis();

  // Debounce button input
  int reading = digitalRead(buttonPin);
  if (reading == LOW && currentMillis - lastDebounceTime > debounceDelay) {
    lastDebounceTime = currentMillis;
    keyboardActive = !keyboardActive;
  }

  if (keyboardActive) {
    float frequency = frequencyMeter.read();
    int volume = analogRead(A0);

    // Check if the frequency is close to 500 Hz and volume exceeds threshold
    if (abs(frequency - targetFrequency) <= frequencyTolerance && volume > threshold) {
      Keyboard.press(KEY_SPACE);
      delay(100);
      Keyboard.release(KEY_SPACE);
    }
  }

  // Print volume every half second
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    // Serial.println(analogRead(A0)); // Print the volume
  }
}
