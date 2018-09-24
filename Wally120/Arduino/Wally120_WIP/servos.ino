void servosFront(){

  //back servos
  servoBB.write(servoBB_out);
  servoBT.write(servoBT_out);
  delay (50);
  //front servos
  servoFB.write(servoFB_in);
  servoFT.write(servoFT_in);
  delay (2000);
}

void servosBack(){
  
  //front servos
  servoFB.write(servoFB_out);
  servoFT.write(servoFT_out);
  delay (50);
  //back servos
  servoBB.write(servoBB_in);
  servoBT.write(servoBT_in);
  delay (2000);
}

void servosNoneFront(){
  //back servos
  servoBB.write(servoBB_out);
  servoBT.write(servoBT_out);
  delay (50);
  //front servos
  servoFB.write(servoFB_mid);
  servoFT.write(servoFT_in);
  delay (2000);
}

void servosNoneBack(){
  //front servos
  servoFB.write(servoFB_out);
  servoFT.write(servoFT_out);
  delay (50);
  //back servos
  servoBB.write(servoBB_out);
  servoBT.write(servoBT_out);
  delay (2000);
}
