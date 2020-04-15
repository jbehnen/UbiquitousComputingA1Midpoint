const int LED_OUTPUT_PIN = 3;

void setup() {
  // Set Pin 3 to output
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  // blink on
  digitalWrite(LED_BUILTIN, HIGH); // output 5V
  delay(1000);
  // blink off
  digitalWrite(LED_BUILTIN, LOW);  // output 0V
  delay(1000);
}
