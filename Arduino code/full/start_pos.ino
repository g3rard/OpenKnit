// començant sempre per la dreta

//dis1 el guifils del maniga dreta al principi de la seva part
//disFin1 el guiafils del  maniga dreta al final de la seva part
//dis2 el guifils del cos al principi de la seva part
//disFin2 el guiafils de cos al final de la seva part
//dis3 el guifils del maniga esquerra al principi de la seva part
//disFin3 el guiafils del maniga esquerra al final de la seva part

//fer un condicional per veure en quin homing esta i veure en quina direccio 
//s'ha de moure el carro per arribar a X posicio, en funcio del encoder
//posicio o distancia en funcio de si va amb steps o el encoder...

void start_pos() {

  servoT.write(105);       //agafa el guiafils del cos
  delay(200);

  getDis2();   

  servoT.write(140);       //deixa el guiafils del cos
  delay(200);

  //CCW
  digitalWrite(reset, LOW);    
  delay(10);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, LOW);

  for ( j = 0; j<passos; j++)   //carro buit a l'esquerra= homingB
  {
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat);   
  } 

  servoT.write(55);       //agafa el guiafils de la maniga esquerra
  delay(200);

  getDis3();

  servoT.write(140);       //deixa el guiafils de la maniga esquerra
  delay(200);

  homingA();
  
} 

void getDis2() {
  //CCW
  digitalWrite(reset, LOW);    
  delay(10);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, LOW);

  for ( j = 0; j<dis2+marge; j++)   //porta el guiafils del cos a pos2 / pos2 per definir, steps or encoder 
                                    //li sumem el marge ja que no es el mateix la punta de la leva i la punta del guiafils, leva 5cm mes avançada
  {
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat);   
  } 
}


void getDis3(){
  //CW
  digitalWrite(reset, LOW);    
  delay(10);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, HIGH);

  for ( i = 0; i<dis3+marge; i++)   //porta el guiafils de la maniga esquerra a pos3 / pos3 per definir, steps or encoder
                                    //li sumem el marge ja que no es el mateix la punta de la leva i la punta del guiafils, leva 5cm mes avançada
  {
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat);   
  } 
}

void getDis1() {
  //CCW
  digitalWrite(reset, LOW);    
  delay(10);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, LOW);

  for ( j = 0; j<dis1+marge; j++)   //porta el guiafils del cos a pos2 / pos2 per definir, steps or encoder                                  
                                    //li sumem el marge ja que no es el mateix la punta de la leva i la punta del guiafils, leva 5cm mes avançada
  {
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   
    delayMicroseconds(velocitat);   
  } 
}


