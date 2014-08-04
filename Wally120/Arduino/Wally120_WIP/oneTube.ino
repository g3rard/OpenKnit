void oneTube (){


  delay(1000);

  while(numberRows < 91){
    Serial.print ("row  ");
    Serial.println(numberRows);
    delay(10);

    if (needleBed == 1){ 

      //back servos
      servoBB.write(servoBB_out); //137
      servoBT.write(servoBT_out);
      delay (50);
      //front servos
      servoFB.write(servoFB_in);  //middle
      servoFT.write(servoFT_in);  //in
      delay (50);

      digitalWrite(reset, LOW);    
      delay(100);
      digitalWrite(reset, HIGH);    
      digitalWrite(dir, LOW); 

      for (i = 0; i<stepsRotation; i++){
        digitalWrite(steps, HIGH);  
        digitalWrite(steps, LOW);   
        delayMicroseconds(speedRotation);
        //        Serial.println(needle);

        needle = encoderValue/11.8;

        if(needle > maxNeedle) {  
          i = stepsRotation++;
          needleBed = 2;
          delay(100);
        }
      } 
    }

    //CW, moving right
    if (needleBed == 2){   

      //front servos
      servoFB.write(servoFB_out);  //top
      servoFT.write(servoFT_out);  //in
      //back servos
      servoBB.write(servoBB_in); //102
      servoBT.write(servoBT_in);
      delay (50);

      digitalWrite(reset, LOW);    
      delay(100);
      digitalWrite(reset, HIGH);   
      digitalWrite(dir, HIGH); 

      for ( j = 0; j<stepsRotation; j++){
        digitalWrite(steps, HIGH);  
        digitalWrite(steps, LOW);   
        delayMicroseconds(speedRotation);
        needle = encoderValue/11.8;


        if(needle < minNeedle) { 
          j = stepsRotation++;
          needleBed = 1;
        }      
      } 
    }
    numberRows++;
  }
}








