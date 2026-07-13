// STM32 Blue Pill onboard LED blink test
// Arduino IDE + STM32 Arduino Core

#ifndef LED_BUILTIN
#define LED_BUILTIN PC13
#endif

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
}
