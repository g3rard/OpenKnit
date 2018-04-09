void oneTube () {


//  delay(3000);

  while (numberRows < 100) {
    Serial.print ("row  ");
    Serial.println(numberRows);
    delay(10);

    if (needleBed == 1) {

      servosFront();
     
      digitalWrite(reset, LOW);
      delay(100);
      digitalWrite(reset, HIGH);
      digitalWrite(dir, LOW);

      for (i = 0; i < stepsRotation; i++) {
        digitalWrite(steps, HIGH);
        digitalWrite(steps, LOW);
        delayMicroseconds(speedRotation);

        Serial.println("left:");
        Serial.println(encoderValue);

        if (encoderValue >= 840) {  //limits the movement to the left
          i = stepsRotation++;
          needleBed = 2;
        }
      }
    }

    //CW, moving right
    if (needleBed == 2) {

      servosBack();

      digitalWrite(reset, LOW);
      delay(100);
      digitalWrite(reset, HIGH);
      digitalWrite(dir, HIGH);

      for ( j = 0; j < stepsRotation; j++) {
        digitalWrite(steps, HIGH);
        digitalWrite(steps, LOW);
        delayMicroseconds(speedRotation);

        Serial.println("right:");
        Serial.println(encoderValue);

        if (encoderValue <= 0) {  //limits the movement to the right
          j = stepsRotation++;
          needleBed = 1;
        }
      }
    }
    numberRows++;
  }
}








