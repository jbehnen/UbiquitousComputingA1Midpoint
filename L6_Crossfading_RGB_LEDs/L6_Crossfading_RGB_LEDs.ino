const int RGB_RED_PIN = 6;
const int RGB_GREEN_PIN  = 5;
const int RGB_BLUE_PIN  = 3;
const int DELAY_MS = 20; // delay in ms between changing colors
const int MAX_COLOR_VALUE = 255;

enum RGB {
  RED,
  GREEN,
  BLUE,
  NUM_COLORS
};

int _rgbLedValues[] = {255, 0, 0}; // Red, Green, Blue
enum RGB _curFadingUpColor = GREEN;
enum RGB _curFadingDownColor = RED;
const int FADE_STEP = 5;

void setup() {
  // Set the red, green, and blue RGB LED pins as output
  pinMode(RGB_RED_PIN, OUTPUT);
  pinMode(RGB_GREEN_PIN, OUTPUT);
  pinMode(RGB_BLUE_PIN, OUTPUT);

  // Verify expected colors using Serial Monitor
  Serial.begin(9600);
  Serial.println("Red, Green, Blue");

  // Set initial color
  setColor(_rgbLedValues[RED], _rgbLedValues[GREEN], _rgbLedValues[BLUE]);
  delay(DELAY_MS);
}

void loop() {
  // Increment and decrement RGB LED values for current fade up/down colors
  _rgbLedValues[_curFadingUpColor] += FADE_STEP;
  _rgbLedValues[_curFadingDownColor] -= FADE_STEP;

  // If fade up is maxed, rotate colors
  if(_rgbLedValues[_curFadingUpColor] > MAX_COLOR_VALUE) {
    _rgbLedValues[_curFadingUpColor] = MAX_COLOR_VALUE;
    _curFadingUpColor = (RGB)((int)_curFadingUpColor + 1);

    if(_curFadingUpColor >= NUM_COLORS) {
      _curFadingUpColor = RED;
    }
  }

  // If fade down is minimum, rotate colors
  if(_rgbLedValues[_curFadingDownColor] < 0) {
    _rgbLedValues[_curFadingDownColor] = 0;
    _curFadingDownColor = (RGB)((int)_curFadingDownColor + 1);

    if(_curFadingDownColor >= NUM_COLORS) {
      _curFadingDownColor = RED;
    }
  }

  // Set the color and then delay
  setColor(_rgbLedValues[RED], _rgbLedValues[GREEN], _rgbLedValues[BLUE]);
  delay(DELAY_MS);
}

/**
 * setColor takes in values between 0 - 255 for the amount of red, green, and blue, respectively
 * where 255 is the maximum amount of that color and 0 is none of that color. You can illuminate
 * all colors by intermixing different combinations of red, green, and blue
 * 
 * This function is based on https://gist.github.com/jamesotron/766994
 */
 void setColor(int red, int green, int blue) {
  Serial.print(red);
  Serial.print(", ");
  Serial.print(green);
  Serial.print(", ");
  Serial.println(blue);

  analogWrite(RGB_RED_PIN, red);
  analogWrite(RGB_GREEN_PIN, green);
  analogWrite(RGB_BLUE_PIN, blue);
 }
