// STM32 Blue Pill onboard LED blink test
// Arduino IDE + STM32 Arduino Core

#ifndef LED_BUILTIN
#define LED_BUILTIN PC13
#endif

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // The Blue Pill onboard LED on PC13 is usually active-low.
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
}
