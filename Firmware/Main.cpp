#include <Servo.h>

Servo esc;
int potPin = 1; // P2 on Digispark is Analog Input 1
int escPin = 0; // P0 on Digispark is PWM output

void setup() {
  esc.attach(escPin);
  esc.writeMicroseconds(1000); // Send minimum throttle to arm the ESC
  delay(2000); // Wait for ESC to initialize
}

void loop() {
  int potValue = analogRead(potPin);
  int throttle = map(potValue, 0, 1023, 1000, 2000); // Map to standard ESC microsecond range
  esc.writeMicroseconds(throttle);
  delay(15);
}