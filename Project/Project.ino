// pin define
#define encoderLPinA  2
#define encoderLPinB  3
#define encoderRPinA 21
#define encoderRPinB 20 
#define motorLIn1 6
#define motorLIn2 7
#define motorRIn1 4
#define motorRIn2 5
// structure parameters
#define RADIUS 3.35
#define PPR 374
#define WIDTH 16.5    //19.7
// In1> In2 : forward
// In1< In2 : backward
// encoder parameters
volatile int encoderLPre; // left
volatile int encoderRPre; // right
int encoderLPrior = 0; // prior left encoder
int encoderRPrior = 0; // prior right encoder
// time parameters
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
float x, y, theta, dtheta; 
// parameters for linear and angular velocity error (velocity control)
float omega_error, omega_error_sum = 0;
float linear_error, linear_error_sum = 0;
// parameters for angle error (yaw control)
float angle_error, angle_error_sum=0;
// path following state parameter
int state=0;
void setup() {
  Init();  
}

void loop() {
  wheel_odometry();
//  if(state==0)
//  {
//    if(tracking('X', 0.915)) 
//    {
//      state++;
//      // clear error sum
//      clear_sum();
//    }
//  }
//  if(state==1)
//  {
//    if(turn(PI/2))  state++;
//  }
//  if(state==2)
//  {
//    if(tracking('Y', 0.61)) 
//    {
//      state++;
//      // clear error sum
//      clear_sum();
//    }
//  }
//  if(state==3)
//  {
//    if(turn(0)) state++;
//  }
//  if(state==4)
//  {
//    if(tracking('X', 1.525)) pwm_control(0,0); 
//  }
//  showData();
  joystick();
  Serial.print(pwmL);Serial.print(" ");Serial.println(pwmR);
  //velocity_control(30,0);
  //Serial.print(speedLR);Serial.print(" ");Serial.println(omega);
}


