void bodyAndSleeves (int needleArmholeFrontRight, int needleArmholeFrontLeft, int needleArmholeBackLeft, int needleArmholeBackRight){

  int margeSeparacio = 39; //the difference in encoder steps (encoderValue) between the front part of the carriage and the center of the carriage

  int ArmholeFrontRight = needleArmholeFrontRight*encoderStepsNeedle+margeSeparacio; //the number of encoder steps, the encoderValue target 
                                                                                     //where guide thread is going to be changed
  int ArmholeFrontLeft = needleArmholeFrontLeft*encoderStepsNeedle+margeSeparacio;
  int ArmholeBackLeft = needleArmholeBackLeft*encoderStepsNeedle+margeSeparacio;
  int ArmholeBackRight = needleArmholeBackRight*encoderStepsNeedle+margeSeparacio;

  int threadGuideFront = 102; //servo value to pick the thread guide in the front
  int threadGuideBack = 62; 

  if (needleBed == 1){ 
    digitalWrite(reset, LOW);    
    delay(100);
    digitalWrite(reset, HIGH);    
    digitalWrite(dir, LOW); 

    for (i = 0; i<stepsRotation; i++){
      digitalWrite(steps, HIGH);  
      digitalWrite(steps, LOW);   
      delayMicroseconds(speedRotation);

      if(ArmholeFrontRight == encoderValue){
        digitalWrite(solenoidTop, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay (50); 
        encoderValue++;
      }
      if(ArmholeFrontLeft == encoderValue){
        digitalWrite(solenoidTop, LOW);   // turn the LED on (HIGH is the voltage level)
        delay (50); 
        encoderValue++;
      }
    } 
  }

  //CW, moving right
  if (needleBed == 2){   

    digitalWrite(reset, LOW);    
    delay(100);
    digitalWrite(reset, HIGH);   
    digitalWrite(dir, HIGH); 

    for ( j = 0; j<stepsRotation; j++){
      digitalWrite(steps, HIGH);  
      digitalWrite(steps, LOW);   
      delayMicroseconds(speedRotation);

      if(ArmholeBackLeft == encoderValue){
        digitalWrite(solenoidTop, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay (50); 
        encoderValue++;
      }
      if(ArmholeBackRight == encoderValue){
        digitalWrite(solenoidTop, LOW);   // turn the LED on (HIGH is the voltage level)
        delay (50); 
        encoderValue++;

      }
    } 
  }
}






