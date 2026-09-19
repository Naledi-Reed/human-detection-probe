#include <LiquidCrystal.h>

// Human Detection Probe - portfolio firmware
// Arduino Uno pin allocation
const int PIR_PIN = 2;
const int BUTTON_PIN = 7;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;

// LCD pins: RS, Enable, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

bool lastMotionState = false;
unsigned long lastDisplayUpdate = 0;

void showReadyScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Detection Probe");
  lcd.setCursor(0, 1);
  lcd.print("Status: READY");
}

void showMotionAlert() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HUMAN PRESENCE");
  lcd.setCursor(0, 1);
  lcd.print("CHECK LOCATION");
}

void runDiagnosticTest() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DIAGNOSTIC TEST");

  digitalWrite(LED_PIN, HIGH);
  tone(BUZZER_PIN, 1200, 500);

  lcd.setCursor(0, 1);
  lcd.print("LED + BUZZER OK");
  delay(1000);

  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);
  showReadyScreen();
}

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Initialising...");
  delay(1500);

  showReadyScreen();
}

void loop() {
  const bool motionDetected = digitalRead(PIR_PIN) == HIGH;
  const bool diagnosticPressed = digitalRead(BUTTON_PIN) == LOW;

  if (diagnosticPressed) {
    runDiagnosticTest();
    delay(250);  // Basic button debounce
    return;
  }

  if (motionDetected) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);

    if (!lastMotionState) {
      showMotionAlert();
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);

    if (lastMotionState || millis() - lastDisplayUpdate > 5000) {
      showReadyScreen();
      lastDisplayUpdate = millis();
    }
  }

  lastMotionState = motionDetected;
  delay(100);
}
