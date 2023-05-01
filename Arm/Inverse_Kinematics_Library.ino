#include <FABRIK2D.h>
#include <Servo.h>
#define ShoulderPin 9
#define ElbowPin 10
#define TheCLAWPin 11
int LStickX, LStickY, RStickX, RStickY;
int deadZone = 20, endZone = 240;
int xplane = 0, yplane = 0;
int shoulderAngle = 0, elbowAngle = 0;
int x_min = 0, x_max = 200, y_min = 0, y_max = 200;

int lengths[] = {199, 226};
Fabrik2D fabrik2D(3, lengths);
Servo shoulder;
Servo elbow;

void setup() 
{
  Serial.begin(9600);
  shoulder.attach(ShoulderPin, -180, 180);
  elbow.attach(ElbowPin, -180, 180);
  fabrik2D.setTolerance(0.5);
}

#define num 256
byte inputs[num] = {};
byte header[4] = {255, 254, 253, 252};
void loop()
{
  if (Serial.available() > 0)
  {
    int numBytes = Serial.readBytes(inputs, num);
    if (numBytes >= 8)
    {
      int h = 0;
      int i;
      for (i = 0; i < numBytes; i++)
      {
        if (inputs[i] == header[h])
        {
          if (h == 3)
          { //found it
            i++;
            break;
          }
          h++;
        }
        else
        {
          h = 0;
        }
      }
      if (i < numBytes - 4)
      {
        LStickX = inputs[i] - 128;
        LStickY = inputs[i + 1] - 128;
        RStickX = inputs[i + 2] - 128;
        RStickY = inputs[i + 3] - 128;
        Start = inputs[i + 4];
        
        LStickX = map(LStickX, -128, 128, -255, 255);
        LStickY = map(LStickY, -128, 128, -255, 255);
        RStickX = map(RStickX, -128, 128, -255, 255);
        RStickY = map(RStickY, -128, 128, -255, 255);
      }
      while (Serial.available() > 0)
      {
        Serial.read();
      }
    }

  }
  if (LStickX <= deadZone && LStickX >= -deadZone) 
  {
    LStickX = 0;
  }
  if (LStickY <= deadZone && LStickY >= -deadZone) 
  {
    LStickY = 0;
  }
  if (RStickX <= deadZone && RStickX >= -deadZone) 
  {
    RStickX = 0;
  }
  if (RStickY <= deadZone && RStickY >= -deadZone) 
  {
    RStickY = 0;
  }

  if (LStickX > endZone) 
  {
    LStickX = 255;
  }
  if (LStickY > endZone) 
  {
    LStickY = 255;
  }
  if (RStickX > endZone) 
  {
    RStickX = 255;
  }
  if (RStickY > endZone) 
  {
    RStickY = 255;
  }

  if (LStickX < -endZone) 
  {
    LStickX = -255;
  }
  if (LStickY < -endZone) 
  {
    LStickY = -255;
  }
  if (RStickX < -endZone) 
  {
    RStickX = -255;
  }
  if (RStickY < -endZone) 
  {
    RStickY = -255;
  }



  xplane += LStickY;
  if(xplane >= x_max)
  {
    xplane = x_max;
  }
  else if(xplane <= x_min)
  {
    xplane = x_min;
  }

  
  yplane += RStickY;
  if(yplane >= y_max)
  {
    yplane = y_max;
  }
  else if(yplane <= y_min)
  {
    yplane = y_min;
  }
  
  currentShoulderAngle = shoulderAngle;
  currentElbowAngle = elbowAngle;
  fabrik2D.solve(xplane,yplane,lengths);
  shoulderAngle = fabrik2D.getAngle(0) * RAD_TO_DEG;
  elbowAngle = fabrik2D.getAngle(1) * RAD_TO_DEG;
  if(shoulderAngle > currentShoulderAngle)
  {
    for(int i = currentshoulderAngle; i <= shoulderAngle; i+=1)
    {
      shoulder.write(i);
      delay(10);
    }
  }
  else if(shoulderAngle <= currentShoulderAngle)
  {
    for(int i = currentshoulderAngle; i >= shoulderAngle; i-=1)
    {
      shoulder.write(i);
      delay(10);
    }
  }

  if(elbowAngle > currentElbowAngle)
  {
    for(int i = currentElbowAngle; i <= elbowAngle; i+=1)
    {
      elbow.write(i);
      delay(10);
    }
  }
  else if(elbowAngle < currentElbowAngle)
  {
    for(int i = currentElbowAngle; i >= elbowAngle; i-=1)
    {
      elbow.write(i);
      delay(10);
    }
  }
  if(Start == 1)
  {
    while(shoulderAngle != -180 || elbowAngle != 180)
    {
      if(shoulderAngle >= -180)
      {
       shoulderAngle -= 5;
       shoulder.write(shoulderAngle); 
      }
      if(elbowAngle <= 180)
      {
       elbowAngle += 5;
       shoulder.write(elbowAngle); 
      }
    }
  }
}
