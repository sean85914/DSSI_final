void Init()
{
  // Set pin mode
  pinMode(encoderLPinB, INPUT);
  pinMode(encoderRPinB, INPUT);
  pinMode(motorLIn1, OUTPUT);
  pinMode(motorLIn2, OUTPUT);
  pinMode(motorRIn1, OUTPUT);
  pinMode(motorRIn2, OUTPUT);
  // Declare interrupt
  attachInterrupt(0, EncoderL, RISING);
  attachInterrupt(2, EncoderR, RISING);
  // Parameters
  // Sampling time
  dt = 100;
  // Initial PWMs
  pwmL = 0;
  pwmR = 0;
  // angular PI
  // angle_KP = 20;
  //angle_KI = 6;
  // linear PI
  //linear_KP = 1.5;
  //linear_KI = 1;
  // PI coefficients tuned by hand
  // Wheel odometry
  x = 0;
  y = 0;
  theta = 0;
  
  // Begin Serial
  Serial.begin(9600);
  // Record the start time
  now = millis();
}

