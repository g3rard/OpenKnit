void servosFront(){

  //back servos
  servoBB.write(servoBB_out);
  servoBT.write(servoBT_out);
  delay (50);
  //front servos
  servoFB.write(servoFB_in);
  servoFT.write(servoFT_in);
  delay (50);
}

void servosBack(){
  
  //front servos
  servoFB.write(servoFB_out);
  servoFT.write(servoFT_out);
  //back servos
  servoBB.write(servoBB_in);
  servoBT.write(servoBT_in);
  delay (50);
}
