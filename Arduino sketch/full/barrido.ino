void barrido(){

  //FRONT
  digitalWrite(reset, LOW);    
  delay(100);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, LOW);     // LOW > front  /  HIGH > back

  getDis1();  
  servoF.write(50);        
  delay(100);
  getDis2();
  servoF.write(85);        
  delay(100);

  homingB();

  //BACK
  digitalWrite(reset, LOW);    
  delay(100);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, HIGH);     // LOW > front  /  HIGH > back

  getFin3();  
  servoB.write(50);        
  delay(100);
  getDis2();
  servoB.write(85);        
  delay(100);
  
  homingA();
}



