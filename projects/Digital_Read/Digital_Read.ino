// STM32 Blue Pill Digital Read example
// Arduino IDE + STM32 Arduino Core


#define BUTTON_PIN PA0
#define LED_PIN    PC13

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

 
  digitalWrite(LED_PIN, HIGH);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    
    digitalWrite(LED_PIN, LOW);   
  } else {
    
    digitalWrite(LED_PIN, HIGH);
  }

  delay(20); 
}
