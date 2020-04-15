const int DELAY_MS = 1000; // delay for 1 sec between blinks
const int RGB_RED_LED_PIN = 6;
const int RGB_GREEN_LED_PIN = 5;
const int RGB_BLUE_LED_PIN = 3;

void setup() {
  // Set the red, green, and blue RGB LED pins as output
  pinMode(RGB_RED_LED_PIN, OUTPUT);
  pinMode(RGB_GREEN_LED_PIN, OUTPUT);
  pinMode(RGB_BLUE_LED_PIN, OUTPUT);
}

// Function expects either HIGH or LOW for each parameter
void setRgbLedColor(int red, int green, int blue) {
  digitalWrite(RGB_RED_LED_PIN, red);
  digitalWrite(RGB_GREEN_LED_PIN, green);
  digitalWrite(RGB_BLUE_LED_PIN, blue);
}

void loop() {
  // red
  setRgbLedColor(HIGH, LOW, LOW);
  delay(DELAY_MS);

  // green
  setRgbLedColor(LOW, HIGH, LOW);
  delay(DELAY_MS);

  // blue
  setRgbLedColor(LOW, LOW, HIGH);
  delay(DELAY_MS);

  // purple
  setRgbLedColor(255, LOW, HIGH);
  delay(DELAY_MS);

  // turquoise
  setRgbLedColor(LOW, HIGH, HIGH);
  delay(DELAY_MS);

  // white
  setRgbLedColor(HIGH, HIGH, HIGH);
  delay(DELAY_MS);
}
