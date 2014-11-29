//encoder
void updateEncoder(){

  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue = encoderValue + increment;
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue = encoderValue - increment;

  lastEncoded = encoded; //store this value for next time
}


//end stop
void endStop() {
  j = stepsRotation++;
  needleBed = 1;
  dirRotation = LOW;
  increment = 1;
  encoderValue = 0;      //value is reset so starts counting needles from 0  15.5
}





