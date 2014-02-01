#define velocitat 900 
#include <Servo.h> 

//inputs de p5 no?
int ampleManiga; //mm
int ampleCos;
int llargManiga;
int llargCos;
//dir-li des de processing on comnençar partint de home (dreta maquina), o fer-ho partint del centre, ja que la peça es simetrica
int dis1;    //distancia (steps o encoder) entre home i inici maniga dreta
int dis2;    //distancia (steps o encoder) entre home i inici cos
int dis3;    //distancia (steps o encoder) entre home i inici maniga esquerra

//p5
int coll;   

int needles1;   // 10mm=2agulles 
int needles2;  
int needles3;   // 10mm=2agulles

int disFin1;    
int disFin2;   
int disFin3;    

int marge;    //diferencia entre guiafils i punta leva, 5cm aprox, encoder o steps
int buttonPin;     // the number of the pushbutton pin
int buttonState;

Servo servoF; 
Servo servoB;
Servo servoT;

int steps;
int dir;
int reset;
int passos;
int i;
int j;
int para;
int totalWidthMachine;
int width3Needles;
int currentNeedle;
int encoderNeedle; 
int carriageDir;


void setup() {
  marge = 10;    //diferencia entre guiafils i punta leva, 5cm aprox, encoder o steps
  buttonPin = 44;     // the number of the pushbutton pin
  buttonState = 0;
  encoderNeedle = 2;
  carriageDir = 1;

  
  steps = 4;
  dir = 6;
  reset = 9;
  passos = 40000;
  totalWidthMachine = 1800;
  width3Needles = 20;
  
  pinMode(steps, OUTPUT); 
  pinMode(dir, OUTPUT); 
  pinMode(reset, OUTPUT);

  servoF.attach(7);   // FRONT
  servoB.attach(8);   // BACK
  servoT.attach(10);  // TOP

  //homing
  attachInterrupt(2, homing0, CHANGE);
  attachInterrupt(3, homing1, CHANGE);

  //guiafils
  attachInterrupt(22, servoCos, FALLING);
  attachInterrupt(24, sManiga, FALLING);
  
  //encoder
  attachInterrupt(0, needleCounter, RISING);

}

void loop(){
  
}

void receiveFromP5(){
  ampleManiga = 50; //mm
  ampleCos = 100;
  llargManiga = 300;
  llargCos = 200;
//   = totalWidthMachine-( ampleCos+(ampleManiga*2)+);
  //dir-li des de processing on comnençar partint de home (dreta maquina), o fer-ho partint del centre, ja que la peça es simetrica
  dis1 = 0;    //distancia (steps o encoder) entre home i inici maniga dreta
  dis2 = 0;    //distancia (steps o encoder) entre home i inici cos
  dis3 = 0;    //distancia (steps o encoder) entre home i inici maniga esquerra
  
  createNewSweater();
  createNewSweater();
}

void createNewSweater(){
  coll = (llargCos-llargManiga);   
  needles1 = (ampleManiga*2/10);   // 10mm=2agulles 
  needles2 = (ampleCos*2/10);  
  needles3 = needles1;   // 10mm=2agulles
  disFin1 = dis1+needles1;    
  disFin2 = dis2+needles2;   
  disFin3 = dis3+needles3;   
}

void makeSweater(){
  // place servers to origin place
  servoB.write(80);  //centre 73
  delay(100);   
  servoF.write(132); //dalt 132
  delay(100); 
  
  homingA();
  currentNeedle = 0; 
  start_pos();
  // takes one yes one no to have a nice end
  everyother();
  
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {     //s'apreta despres de colocar els pesos per continuar 
    all_in(); 
    side2side();
    _1guiafils();
    aixella();
    if (buttonState == HIGH) {     //s'apreta despres de colocar els pesos per continuar 
      barrido();

//      E minvat pos1 action, end pos3 action
//        leva2 side to side
//        repeat x
//        stop

    }
  }
  
}
