
void aixella1(){
  //CCW
  for ( i = 0; i<dis1+needles1+50; i++)   //porta el guiafils de la maniga esquerra a pos3 / pos3 per definir, steps or encoder  /  50 passos = 1 agulla
    //li sumem el marge ja que no es el mateix la punta de la leva i la punta del guiafils, leva 5cm mes avançada
  {
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat);   
  } 
}

void aixella2(){
  //CW
  for ( i = 0; i<dis2+needles2+50; i++)   //porta el guiafils de la maniga esquerra a pos3 / pos3 per definir, steps or encoder  /  50 passos = 1 agulla
    //li sumem el marge ja que no es el mateix la punta de la leva i la punta del guiafils, leva 5cm mes avançada
  {
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat);   
  } 
}

void alapar2F(){
  servoF.write(50);        
  delay(100);

  for (int pos = 50; pos<88; pos++) {     // servoF 86 to 124 >38
    servoF.write(pos);       //centre108
    delay(10);

    for (int g = 0; g<2; g++) {     //2
      digitalWrite(steps, HIGH);  
      digitalWrite(steps, LOW);   
      delayMicroseconds(velocitat*2);   
    } 
  } 
  for (int g = 0; g<10; g++) {     //10 // total 86 steps
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat*2);   
  }    
}

void alapar2B(){
  servoB.write(50);        
  delay(100);

  for (int pos = 50; pos<88; pos++) {     // servoF 86 to 124 >38
    servoB.write(pos);       //centre108
    delay(10);

    for (int g = 0; g<2; g++) {     //2
      digitalWrite(steps, HIGH);  
      digitalWrite(steps, LOW);   
      delayMicroseconds(velocitat*2);   
    } 
  } 
  for (int g = 0; g<10; g++) {     //10 // total 86 steps
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat*2);   
  }    
}



void aixella(){

  //FRONT
  digitalWrite(reset, LOW);    
  delay(100);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, LOW);     // LOW > front  /  HIGH > back

  servoF.write(85);       //centre108  //baix 90, 77
  delay(50); 
  servoB.write(108);       //dalt 85
  delay(50); 

  aixella1();
  alapar2F();
  aixella2();
  alapar2F();

  homingB();

  //BACK
  digitalWrite(reset, LOW);    
  delay(100);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, HIGH);     // LOW > front  /  HIGH > back

  servoF.write(108);       //dalt 132
  delay(50); 
  servoB.write(88);       //centre 73, 82 //baix 37 
  delay(50);   

  aixella2();
  alapar2B();
  aixella1();
  alapar2B();

  homingA();
}



