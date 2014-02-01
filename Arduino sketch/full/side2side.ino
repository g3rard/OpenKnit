void side2side() {
  for ( i = 0; i<llargManiga; i++){
    frontKnit();
    backKnit();    
  }
}

void frontKnit(){
  servoF.write(85);       //centre108  //baix 90, 77
  delay(50); 
  servoB.write(108);       //dalt 85
  delay(50);  

  //CCW
  digitalWrite(reset, LOW);    
  delay(10);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, LOW);

  for ( i = 0; i<passos; i++){
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   //sentit de la direccio
    delayMicroseconds(velocitat);   
    if(para == 1){
      servoT.attach(10);  // TOP
      delay (200);
      servoT.write(105);       //cos
      delay(200);
      para = 0;
      servoT.detach(); 
      delay(200);
    }else if (para == 2){
      servoT.attach(10);  // TOP
      delay (200);
      servoT.write(55);       //maniga
      delay(200);
      para = 0;
      servoT.detach(); 
      delay(200);
    }
  } 
}

void backKnit(){

  servoF.write(108);       //dalt 132
  delay(50); 
  servoB.write(88);       //centre 73, 82 //baix 37 
  delay(50);   

  //CW
  digitalWrite(reset, LOW);    
  delay(10);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, HIGH);

  for ( j = 0; j<passos; j++){
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   //sentit de la direccio
    delayMicroseconds(velocitat); 
    if(para == 1){
      servoT.attach(10);  // TOP
      delay (200);
      servoT.write(55);       //cos
      delay(200);
      para = 0;
      servoT.detach(); 
      delay(200);
    }    
    if (para == 2){
      servoT.attach(10);  // TOP
      delay (200);
      servoT.write(105);       //maniga
      delay(200);
      para = 0;
      servoT.detach(); 
      delay(200);
    }
  } 
}





