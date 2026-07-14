// STM32 Blue Pill Digital Read example
// Arduino IDE + STM32 Arduino Core
//
// Circuit:
// PA0  ---- Push button ---- GND
// PC13 ---- Onboard LED
//
// This uses the internal pull-up resistor.
// Button released = HIGH
// Button pressed  = LOW

#define BUTTON_PIN PA0
#define LED_PIN    PC13

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  // Blue Pill onboard LED on PC13 is usually active LOW.
  digitalWrite(LED_PIN, HIGH); // LED OFF at startup
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    // Button pressed
    digitalWrite(LED_PIN, LOW);   // LED ON
  } else {
    // Button released
    digitalWrite(LED_PIN, HIGH);  // LED OFF
  }

  delay(20); // small debounce/stability delay
}
