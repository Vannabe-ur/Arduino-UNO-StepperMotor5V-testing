#include <Stepper.h>

const int stepsPerRevolution = 2048;  // 28BYJ-48
Stepper stepperMotor(
  stepsPerRevolution,
  8, 10, 9, 11
);

const int joystickPin = A0;
const int buttonPin = 2;

bool motorEnabled = true;
bool lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  stepperMotor.setSpeed(10); // initial speed
  Serial.begin(9600);
}

void loop() {
  int joystickValue = analogRead(joystickPin);
  int offset = joystickValue - 512;

  bool buttonState = digitalRead(buttonPin);

  // Toggle motor enable
  if (buttonState == LOW && lastButtonState == HIGH) {
    motorEnabled = !motorEnabled;
    delay(200);
  }
  lastButtonState = buttonState;

  if (!motorEnabled || abs(offset) < 40) {
    return;  // Dead zone
  }

  int motorSpeed = map(abs(offset), 40, 512, 5, 15);
  stepperMotor.setSpeed(motorSpeed);

  int steps = (offset > 0) ? 10 : -10;
  stepperMotor.step(steps);

  Serial.print("Joystick: ");
  Serial.print(joystickValue);
  Serial.print(" | Speed: ");
  Serial.print(motorSpeed);
  Serial.print(" | Direction: ");
  Serial.println(steps > 0 ? "CW" : "CCW");
}
