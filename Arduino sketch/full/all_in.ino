void all_in() {

  //FRONT
  digitalWrite(reset, LOW);    
  delay(100);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, LOW);     // LOW > front  /  HIGH > back

  getDis1();
  servoF.write(50);    //leva1
  delay(50);
  disNeedles1();
  servoF.write(85);    //leva2
  delay(50);  

  _3_needles ();

  servoF.write(50);    //leva1
  delay(50);
  disNeedles2();
  servoF.write(85);    //leva2
  delay(50);  

  _3_needles ();

  servoF.write(50);    //leva1
  delay(50);
  disNeedles3();
  servoF.write(105);    //leva3
  delay(50);  

  homingB();

    //BACK
  digitalWrite(reset, LOW);    
  delay(100);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, HIGH);     // LOW > front  /  HIGH > back

  getDis1();
  servoB.write(50);    //leva1
  delay(50);
  disNeedles1();
  servoB.write(85);    //leva2
  delay(50);  

  _3_needles ();

  servoB.write(50);    //leva1
  delay(50);
  disNeedles2();
  servoB.write(85);    //leva2
  delay(50);  

  _3_needles ();

  servoB.write(50);    //leva1
  delay(50);
  disNeedles3();
  servoB.write(105);    //leva3
  delay(50);  

  homingA();

}

void disNeedles1(){
  for (int h = 0; h<needles1; h++){
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat);
  }
}

void disNeedles2(){
  for (int h = 0; h<needles2; h++){
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat);
  }
}

void disNeedles3(){
  for (int h = 0; h<needles3; h++){
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat);
  }
}

