int FORWARD_KNIT = 1;
int FORWARD_EMPTY = 2;
int BACKWARD_KNIT = 3;
int BACKWARD_EMPTY = 4;

int direction = FORWARD_KNIT;

int FORWARD_STOP_KNIT = 150 + 200;
int TURNAROUND = FORWARD_STOP_KNIT + 135;

void halfTube () {
  while (numberRows < 100) {
    delay(10);

    if (direction == FORWARD_KNIT) {
      servosFront();
      goForward(FORWARD_STOP_KNIT);
      direction = FORWARD_EMPTY;
    }

    if (direction == FORWARD_EMPTY) {
      servosNoneFront();
      goForward(TURNAROUND);
      direction = BACKWARD_KNIT;
    }

    if (direction == BACKWARD_KNIT) {
      servosBack();
      goBackward(0);
      direction = FORWARD_KNIT;
    }
    
    numberRows++;
  }
}

void goForward(int endpoint) {
  digitalWrite(reset, LOW);
  delay(100);
  digitalWrite(reset, HIGH);
  digitalWrite(dir, LOW);

  for (i = 0; i < stepsRotation; i++) {
    digitalWrite(steps, HIGH);
    digitalWrite(steps, LOW);
    delayMicroseconds(speedRotation);
    
    if (encoderValue >= endpoint) {  //limits the movement to the left
      j = stepsRotation++;
      return;
    }
  }
}

void goBackward(int endpoint) {
  digitalWrite(reset, LOW);
  delay(100);
  digitalWrite(reset, HIGH);
  digitalWrite(dir, HIGH);

  for ( i = 0; i < stepsRotation; i++) {
    digitalWrite(steps, HIGH);
    digitalWrite(steps, LOW);
    delayMicroseconds(speedRotation);
    
    if (encoderValue <= endpoint) {  //limits the movement to the right
      j = stepsRotation++;
      return;
    }
  }
}






