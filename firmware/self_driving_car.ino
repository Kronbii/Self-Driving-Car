// Refactored sketch placeholder: Self-Driving Car (Line Follower)
// This version will evolve toward modular code (sensors, motors, control).
// For now it mirrors the logic of the original `src/Finalprojectcodeeee.ino` with clearer naming.

// Pin assignments
const int PIN_LINE_1 = 2;   // Leftmost (verify physical order)
const int PIN_LINE_2 = 3;
const int PIN_LINE_3 = 4;
const int PIN_LINE_4 = 5;
const int PIN_LINE_5 = 12;
const int PIN_LINE_6 = 13;  // Rightmost (verify)
const int PIN_IR     = 8;   // IR obstacle sensor (future use)

// Motor driver pins
const int PIN_RIGHT_FWD = 10;
const int PIN_RIGHT_REV = 11;
const int PIN_LEFT_FWD  = 9;
const int PIN_LEFT_REV  = 6;

// Runtime sensor states
int s1, s2, s3, s4, s5, s6;

void drive(int leftFwd, int leftRev, int rightFwd, int rightRev) {
  analogWrite(PIN_LEFT_FWD,  leftFwd);
  analogWrite(PIN_LEFT_REV,  leftRev);
  analogWrite(PIN_RIGHT_FWD, rightFwd);
  analogWrite(PIN_RIGHT_REV, rightRev);
}

void setup() {
  // Sensors
  pinMode(PIN_LINE_1, INPUT);
  pinMode(PIN_LINE_2, INPUT);
  pinMode(PIN_LINE_3, INPUT);
  pinMode(PIN_LINE_4, INPUT);
  pinMode(PIN_LINE_5, INPUT);
  pinMode(PIN_LINE_6, INPUT);
  pinMode(PIN_IR, INPUT);

  // Motors
  pinMode(PIN_RIGHT_FWD, OUTPUT);
  pinMode(PIN_RIGHT_REV, OUTPUT);
  pinMode(PIN_LEFT_FWD,  OUTPUT);
  pinMode(PIN_LEFT_REV,  OUTPUT);
}

void loop() {
  s1 = digitalRead(PIN_LINE_1);
  s2 = digitalRead(PIN_LINE_2);
  s3 = digitalRead(PIN_LINE_3);
  s4 = digitalRead(PIN_LINE_4);
  s5 = digitalRead(PIN_LINE_5);
  s6 = digitalRead(PIN_LINE_6);

  // Default forward cruise
  drive(120, 0, 120, 0);

  if (s1 == HIGH) {
    drive(255, 0, 0, 255); // Hard steer left (?) adjust once orientation confirmed
  }
  else if (s2 == HIGH) {
    drive(255, 0, 0, 100);
  }
  else if (s3 == HIGH) {
    drive(0, 150, 255, 0);
  }
  else if (s4 == HIGH) {
    drive(0, 255, 255, 0);
  }
  else if (s5 == HIGH) {
    drive(255, 0, 0, 255);
  }
  else if (s6 == HIGH) {
    drive(0, 255, 255, 0);
  }
  else if (s1 && s2 && s3 && s4 && s5 && s6) {
    drive(120, 0, 120, 0);
  }
}
