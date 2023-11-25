# Freq2HID - Arduino Frequency-Based Keyboard Emulator


This repository contains an Arduino sketch that enables an Arduino MKR WiFi 1010 board to function as a USB keyboard emulator. The code triggers a keypress (specifically, the space key) when a certain audio frequency (around 500 Hz) is detected above a specified volume threshold. Additionally, it prints the audio volume to the Serial Monitor at regular intervals.

## Installation

<img src="logo_freq2hid.png" alt="Arduino Frequency-Based Keyboard Emulator Logo" width="300" align="right">

To use this sketch, you will need:
- An Arduino MKR WiFi 1010 board
- A suitable microphone or audio input device
- The Arduino IDE, available [here](https://www.arduino.cc/en/Main/Software)

### Dependencies

This project relies on the following Arduino libraries:
- `Keyboard.h`
- `AudioFrequencyMeter.h`

These libraries can be installed through the Arduino Library Manager in the Arduino IDE.

## Usage

1. Connect your microphone or audio input device to the A0 pin on your Arduino board.
2. Connect a pushbutton to the specified button pin (default pin 6) and ground.
3. Open the Arduino IDE, load the provided sketch, and upload it to your Arduino MKR WiFi 1010.
4. Open the Serial Monitor to view the audio volume readings.
5. Press the button connected to pin 6 to toggle the keyboard emulation functionality.

## Compatibility

This sketch is primarily designed for the Arduino MKR WiFi 1010 board. However, it should be compatible with other Arduino boards that support USB HID (Human Interface Device) functionality and have analog input capabilities. Some compatible boards include:

- Arduino Leonardo
- Arduino Micro
- Arduino Zero
- Arduino Due

For other Arduino models, modifications may be needed, especially if they do not natively support USB HID capabilities.

## Contributing

Contributions to this project are welcome. To contribute:
1. Fork the repository.
2. Create a new branch for your feature (`git checkout -b feature/AmazingFeature`).
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a pull request.

## License

Distributed under the AGPL 3.0 License. See `LICENSE` for more information.

## Acknowledgments

- This project was inspired by the need for simple, frequency-based input devices for evaluation purposes in scientific research.
- Thanks to the Arduino community for their invaluable resources and support.

