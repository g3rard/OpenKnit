//agafem el guiafils de la maniga esquerra i els altres 2 s'autoseleccionen amb el sensor de hall

void everyother() {

  //FRONT
  digitalWrite(reset, LOW);    
  delay(100);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, LOW);     // LOW > front  /  HIGH > back

  servoT.write(55);       //agafa el guiafils de la maniga esquerra
  delay(200);

  getDis1();

  selection1 ();
  _3_needles ();
  selection2 ();
  _3_needles ();
  selection3 ();

  homingB();
  
  //BACK
  digitalWrite(reset, LOW);    
  delay(100);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, HIGH);     // LOW > front  /  HIGH > back

  getFin3();

  selection3 ();
  _3_needles ();
  selection2 ();
  _3_needles ();
  selection1 ();

  homingA();

}



///////

void selection1 (){
  for (int h = 0; h<needles1; h++){
    selectNeedle();
    alapar();
  }
}

void selection2 (){
  for (int h = 0; h<needles2; h++){
    selectNeedle();
    alapar();
  }
}

void selection3 (){
  for (int h = 0; h<needles3; h++){
    selectNeedle();    //leva1
    alapar();          //leva2 a la vegada avança carro passant una agulla de llarg
  }
}

void _3_needles(){
  for ( i = 0; i< needles3; i++){   //determinar distancia 3 agulles, steps or encoder
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat);     
  }
} 

void selectNeedle(){
  servoF.write(50);        
  delay(100);
}

void alapar(){

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

void getFin3(){
  //CW
  digitalWrite(reset, LOW);    
  delay(10);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, HIGH);

  for ( i = 0; i<(dis3+needles3); i++)   //porta el guiafils de la maniga esquerra a pos3 / pos3 per definir, steps or encoder
  {
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat);   
  } 
}


