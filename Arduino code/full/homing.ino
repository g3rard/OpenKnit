// brings head to end 

// A is frontal head
void homingA() {

  //CW
  digitalWrite(reset, LOW);    
  delay(10);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, HIGH);

  for ( i = 0; i<passos; i++)       
  {
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   //sentit de la dir
    delayMicroseconds(velocitat);   
  } 
  
} 
// B is back head
void homingB() {

  //CW
  digitalWrite(reset, LOW);    
  delay(10);
  digitalWrite(reset, HIGH);   
  digitalWrite(dir, LOW);

  for ( i = 0; i<passos; i++)       
  {
    digitalWrite(steps, HIGH);  
    digitalWrite(steps, LOW);   //sentit de la dir
    delayMicroseconds(velocitat);   
  } 
  
} 
