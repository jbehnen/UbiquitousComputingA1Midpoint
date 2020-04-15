const int LED_OUTPUT_PIN = 3;
const int MAX_ANALOG_OUT = 255; // max analog out on Uno (Leonardo???)
const int DELAY_MS = 5;

void setup() {
  // Set Pin 3 to output
  pinMode(LED_OUTPUT_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // fade on
  for (int i = 0; i <= MAX_ANALOG_OUT; i += 1) {
    Serial.println(i);
    analogWrite(LED_OUTPUT_PIN, i); // output 5V
    delay(DELAY_MS);
  }
  // fade off
  for (int i = MAX_ANALOG_OUT; i >= 0; i -= 1) {
    Serial.println(i);
    analogWrite(LED_OUTPUT_PIN, i); // output 5V
    delay(DELAY_MS);
  }
}
