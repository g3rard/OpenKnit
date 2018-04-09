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

int numberRows = 0;
int needleBed = 1;           //front needle bed = 1 , back needle bed = 2
//(to create tubular sections)the knitting carriage have two identical systems,
//one operating in the front needle bed and the other in the back, they never operate at the same time.
//carriage on the front needle bed operates only going to the left, while going to the right
//the front systems is "deactivated" and the carriage only operates in the back needle bed

//servo
#include <Servo.h>
Servo servoFB;
Servo servoFT;
Servo servoBB;
Servo servoBT;
Servo servoSelection; //not used with Wally120 since it has only one Yarn Carrier

int servoFB_in = 55;  
int servoFB_out = 112; 
int servoFT_in = 85; 
int servoFT_out = 160; 

int servoBB_in = 50;
int servoBB_out = 105;
int servoBT_in = 60;
int servoBT_out = 130;

int servoYarn_in = 65;
int servoYarn_out = 100;


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

  //end stop
  attachInterrupt(0, endStop, CHANGE);  //pin 3

  //servo
  servoFB.attach(7);   // servo in the front needle bed selecting needles
  servoFT.attach(8);   // servo in the front needle bed stopping the loops rising up
  servoBB.attach(9);   // servo in the back needle bed selecting needles
  servoBT.attach(10);   // servo in the back needle bed stopping the loops rising up

  homing();  //carriage goes home before anything else to get coordinatee zero
}

void loop(){
  oneTube();  //scarfs, beanies, dresses (no sleeves), socks, etc
}
