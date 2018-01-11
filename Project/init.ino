void Init()
{
  // Set pin mode
  pinMode(encoderLPinB, INPUT);
  pinMode(encoderRPinB, INPUT);
  pinMode(motorLIn1, OUTPUT);
  pinMode(motorLIn2, OUTPUT);
  pinMode(motorRIn1, OUTPUT);
  pinMode(motorRIn2, OUTPUT);
  pinMode(ledPin, OUTPUT);
  // Declare interrupt
  attachInterrupt(0, EncoderL, RISING);
  attachInterrupt(2, EncoderR, RISING);
  // Parameters
  // Sampling time
  dt = 100;
  // Initial PWMs
  pwmL = 0;
  pwmR = 0;
  // Wheel odometry
  x = 0;
  y = 0;
  theta = 0;
  
  // Begin Serial
  Serial.begin(9600);
  BT.begin(38400);
  // Record the start time
  now = millis();
}

