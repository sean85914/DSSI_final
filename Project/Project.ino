// Libraries
#include<SoftwareSerial.h>
#include<Wire.h>
#include<math.h>
// pin define
#define encoderLPinA  2
#define encoderLPinB  3
#define encoderRPinA 21
#define encoderRPinB 20 
#define motorLIn1 6
#define motorLIn2 7
#define motorRIn1 4
#define motorRIn2 5
#define ledPin 12
// structure parameters
#define RADIUS 3.35
#define PPR 374
#define WIDTH 16.5    //19.7
// In1> In2 : forward
// In1< In2 : backwardc
// encoder parameters
volatile int encoderLPre; // left
volatile int encoderRPre; // right
int encoderLPrior = 0; // prior left encoder
int encoderRPrior = 0; // prior right encoder
// timer parameters
unsigned long dt ; // 10 Hz
unsigned long now;
unsigned long speed_time;
// pwm parameter
double pwmR, pwmL;
// distances motor traveledvoid 
float dis_per_tick = 2* PI* RADIUS / PPR;
float disL, disR;
// velocity parameters
float speedL, speedR, speedLR, omega;
// odometry parameters
float x, y, theta, dtheta, theta_comp; 
// velocity control parameters
float speedR_error, speedR_error_sum = 0;
float speedL_error, speedL_error_sum = 0;
float theta_error_sum = 0;
// parameters for angle error (yaw control)
float angle_error, angle_error_sum=0;
// path following state parameter
int state=0;
// deadzone counter
int count=0;
// Way points
// Wheel
//float way_pointX[10]={0, 0.44, 0.48, 0.96, 1.36, 1.36, 2.02, 0.64, 0.64,    0};
//float way_pointY[10]={0,    0, 0.48, 0.48, 0.48,    0,    0,    0, 0.48, 0.48};
//*/
// Visual
float way_pointX[10]={0.11, 0.39, 0.40, 0.67, 0.96, 0.98, 1.25, 0.39, 0.40, 0.11};
float way_pointY[10]={0.36, 0.36, 0.97, 0.99, 0.98, 0.39, 0.36, 0.36, 0.97, 1.04};
/* copy waMy points
float way_pointX[10]={0, 0.44, 0.48, 0.96, 1.36, 1.36, 1.92, 0.65, 0.64,    0};
float way_pointY[10]={0,    0, 0.48, 0.48, 0.48,    0,    0,    0, 0.48, 0.48};
*/
// path following velocity
float vel = 25; // 20 cm/s
// Is joystick control
int joystick=0;
// BT
SoftwareSerial BT(10, 11);
void setup() {
  Init();  
}

void loop() {
  wheel_odometry();
  getPosition();
  if(joystick==0){
    //pure_pursuit();
    /*if(state==0){if(turn(PI))  state++;}
    if(state==1){if(turn(0))  state++;}
    if(state==2)  pwm_control(0,0);
    Serial.println(state);
    Serial.println(angle_error);*/
  }
  else 
    joystick_control();
  //showData();  
}
