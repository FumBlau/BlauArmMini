#include <Servo.h> // Libreria de Servos

const int SERVOS = 4;
const int ACC = 10; // the accurancy of the potentiometer value before idle starts counting
int PIN[SERVOS], value[SERVOS], idle[SERVOS], currentAngle[SERVOS], MIN[SERVOS], MAX[SERVOS], INITANGLE[SERVOS], previousAngle[SERVOS],ANA[SERVOS];
Servo myservo[SERVOS];


void setup()   {
 ///////////////////////////////////////////////////////////////////////////////////Servo Intermedio
  PIN[0] = 10;
  MIN[0] = 0;
  MAX[0] = 180;
  INITANGLE[0] = 90;
  ANA[0] = 1;
  //Servo Izq
  PIN[1] = 9;
  MIN[1] = 60; 
  MAX[1] = 165;
  INITANGLE[1] = 152;
  ANA[1] = 0;
  //Servo Der
  PIN[2] = 6;
  MIN[2] = 40;
  MAX[2] = 180;
  INITANGLE[2] = 90;
  ANA[2] = 2;
  //Servo pinza
  PIN[3] = 5;
  MIN[3] = 60;
  MAX[3] = 180;
  INITANGLE[3] = 60;
  ANA[3] = 3;
  ////////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < SERVOS; i++){
    myservo[i].attach(PIN[i]);
    myservo[i].write(INITANGLE[i]);
    value[i] = 0;
    idle[i] = 0;
    previousAngle[i]=INITANGLE[i];
  }
}

void loop() {
  delay(10);
    for (int i = 0; i < SERVOS; i++){
      value[i] = analogRead(ANA[i]);
      currentAngle[i] = myservo[i].read();
    
      if (value[i] > 612) {
        idle[i] = 0;
      
        if (currentAngle[i] < MAX[i]) ++currentAngle[i];
        if (!myservo[i].attached()){
          myservo[i].attach(PIN[i]);
        }
        myservo[i].write(currentAngle[i]);     
      } else if (value[i] < 412) {
      idle[i] = 0;
      if (currentAngle[i] > MIN[i]) --currentAngle[i];
      if (!myservo[i].attached()){
        myservo[i].attach(PIN[i]);
      }
      myservo[i].write(currentAngle[i]);    
    } else {
      ++idle[i];
    }
    if (idle[i] > 100){
      myservo[i].detach();
      idle[i] = 0;
    }  
    } 
    } 
