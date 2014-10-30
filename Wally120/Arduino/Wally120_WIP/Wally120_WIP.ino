//stepper
#define speedRotation 1000  //speed of the motor rotation
int steps = A1;
int dir = A2;
int reset = A0;
int stepsRotation = 30000; //steps that the stepper does 
int i;
int j;
int h;
boolean dirRotation = LOW;  //direction of rotation

//encoder
int encoderPin1 = 0;
int encoderPin2 = 1;
volatile int lastEncoded = 0;
volatile long encoderValue = 0;
long lastencoderValue = 0;
int lastMSB = 0;
int lastLSB = 0;
int increment = 1;

//needle selection
#include <math.h>
String readString;  
int needleToGo = 0;          //needle selected to go
int prevNeedleToGo = 0;      //previous needle where the carriage just have been
int encoderStepsNeedle = 6;  //steps of the encoder between two needles   
int needleTarget = 0;        //encoder steps required to get to the needleToGo,  needleTarget = encoderStepsNeedle*needleToGo
int needleBed = 1;           //front needle bed = 1 , back needle bed = 2

float needle = 0;

int headWidth = 60;           //centimeters
float minNeedle = 9;
float maxNeedle = 70;
float rows = 0;
int numberRows = 1;

//(to create tubular sections)the knitting carriage have two identical systems, 
//one operating in the front needle bed and the other in the back, they never operate at the same time.
//carriage on the front needle bed operates only going to the left, while going to the right
//the front systems is "deactivated" and the carriage only operates in the back needle bed
int inputCounter = 0;        //gets how many input orders we do so we can know when is the first one and get the right prevNeedleToGo value 

//servo
#include <Servo.h> 
Servo servoFB; 
Servo servoFT;
Servo servoBB;
Servo servoBT;
Servo servoSelection;

int servoFB_in = 114;
int servoFB_out = 88;
int servoFT_in = 132;
int servoFT_out = 35;

int servoBB_in = 40;
int servoBB_out = 72;
int servoBT_in = 38;
int servoBT_out = 150;

//solenoid
int solenoidTop = 11;  

//WIP
////////////sweater design/////////////
///////////////////////////////////////
int needleArmholeFrontRight = 40;    // starting from the right, the needle where the left arm ends and starts de body, thread is changed
int needleArmholeFrontLeft = 130;    // body ends and starts left arm, thread is changed
int needleArmholeBackLeft = 211;     // same in the back, starting the needle bed from left instead
int needleArmholeBackRight = 301;    // same in the back, the carriage ends on the right, ready to start next row
///////////////////////////////////////


void setup() {
  Serial.begin (9600);

  //stepper
  pinMode(steps, OUTPUT); 
  pinMode(dir, OUTPUT); 
  pinMode(reset, OUTPUT);

  //encoder
  pinMode(encoderPin1, INPUT); 
  pinMode(encoderPin2, INPUT);
  digitalWrite(encoderPin1, HIGH); 
  digitalWrite(encoderPin2, HIGH); 
  attachInterrupt(2, updateEncoder, CHANGE); 
  attachInterrupt(3, updateEncoder, CHANGE);

  //end stops
  //  attachInterrupt(2, endStopL, CHANGE);
  attachInterrupt(0, endStopR, CHANGE);  //pin 3

  //servo
  servoFB.attach(7);   // servo in the front needle bed selecting needles, FrontBottom
  servoFT.attach(8);   // servo in the front needle bed "stopping the loops to go up", FrontTop
  servoBB.attach(9);   // servo in the back needle bed selecting needles, BackBottom
  servoBT.attach(10);   // servo in the back needle bed "stopping the loops to go up", BackTop

  //solenoid
  pinMode(solenoidTop, OUTPUT);

  homing();  //carriage goes home before anything else to get coordinate/needle zero
}

void loop(){ 
  oneTube();  //scarfs, beanies, dresses (no sleeves), t-shirts (no sleeves), etc

  //body and sleeves are knitted till the armpit 
  //bodyAndSleeves (needleArmholeFrontRight, needleArmholeFrontLeft, needleArmholeBackLeft, needleArmholeBackRight);
}




