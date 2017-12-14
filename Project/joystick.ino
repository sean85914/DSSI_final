float pastLinear, pastAngular;
void joystick()
{
  String linear_str, angular_str;
  float linear, angular;
  
  if(Serial.available())
  {
    String command = Serial.readString();
    for(int i=0; i<=command.length();++i)
    {
      if(command[i] == ' ')
      {
          //Serial.print("ha");
          linear_str  = command.substring(0,i);
          angular_str = command.substring(i+1,command.length());
          linear  =  linear_str.toFloat();
          angular = angular_str.toFloat(); 
      }
    }
    velocity_control(linear, angular);
    pastLinear  = linear;
    pastAngular = angular;
  }
  else  {velocity_control(pastLinear, pastAngular);Serial.println(pastLinear);Serial.println(pastAngular);}
}
