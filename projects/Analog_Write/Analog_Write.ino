// STM32 Blue Pill analogWrite PWM fade example
// Arduino IDE + STM32 Arduino Core
//
// Circuit:
// PA6 ---- 220 to 330 ohm resistor ---- LED anode (+)
// GND ------------------------------- LED cathode (-)
//
// PA6 supports timer PWM using TIM3 Channel 1.
// analogWrite() uses values from 0 to 255 in this example.

#define PWM_LED_PIN PA6

void setup() {
  pinMode(PWM_LED_PIN, OUTPUT);
  analogWrite(PWM_LED_PIN, 0); // LED OFF at startup
}

void loop() {
  // Gradually increase the LED brightness.
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(PWM_LED_PIN, brightness);
    delay(10);
  }

  // Gradually decrease the LED brightness.
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(PWM_LED_PIN, brightness);
    delay(10);
  }
}