#include <LiquidCrystal.h>

const int PIR_PIN = 2;
const int LED_PIN = 3;
const int PIEZO_PIN = 4;
const int BUTTON_PIN = 5;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

bool previousButtonState = false;
unsigned long lastButtonChange = 0;
const unsigned long DEBOUNCE_MS = 50;

void showStatus(const char* line1, const char* line2) {
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print(line1);

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIEZO_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  lcd.begin(16, 2);
  showStatus("System Ready", "Initialising...");
  delay(2000);
  showStatus("Monitoring...", "Status: CLEAR");
}

void loop() {
  const bool motionDetected = digitalRead(PIR_PIN) == HIGH;
  const bool rawButtonState = digitalRead(BUTTON_PIN) == HIGH;

  if (rawButtonState != previousButtonState &&
      millis() - lastButtonChange >= DEBOUNCE_MS) {
    previousButtonState = rawButtonState;
    lastButtonChange = millis();
  }

  if (motionDetected) {
    showStatus("MOTION DETECTED!", "Status: ALERT");
    digitalWrite(LED_PIN, HIGH);
    tone(PIEZO_PIN, 1000);
  } else if (previousButtonState) {
    showStatus("Button Pressed", "Status: TESTING");
    digitalWrite(LED_PIN, HIGH);
    tone(PIEZO_PIN, 1500);
    delay(200);
    noTone(PIEZO_PIN);
    digitalWrite(LED_PIN, LOW);
  } else {
    showStatus("Monitoring...", "Status: CLEAR");
    digitalWrite(LED_PIN, LOW);
    noTone(PIEZO_PIN);
  }

  delay(100);
}
