#define FrontRightMotorPower 6
#define MiddleRightMotorPower 12
#define BackRightMotorPower 9
#define FrontLeftMotorPower 3
#define MiddleLeftMotorPower 12
#define BackLeftMotorPower 5
#define FrontRightMotorDirection 7
#define MiddleRightMotorDirection 12
#define BackRightMotorDirection 8
#define FrontLeftMotorDirection 2
#define MiddleLeftMotorDirection 12
#define BackLeftMotorDirection 4
#define FrontRightServo 12
#define MiddleRightServo 12
#define BackRightServo 12
#define FrontLeftServo 12
#define MiddleLeftServo 12
#define BackLeftServo 12
#define num 64
int Lpower, Rpower;
int8_t LStickX, LStickY, RStickX, RStickY, Cross, Circle, Square, Triangle;
int deadZone = 20, endZone = 140, magL, magR, center = 90, driveMode = 2;
double degreeL, degreeR;
byte inputs[num] = {};
byte header[4] = {255, 254, 253, 252};

void LeftJoystickDrive()
{
  Lpower = magL;
  Rpower = magL;
  digitalWrite(FrontLeftServo, center);
  digitalWrite(MiddleLeftServo, center);
  digitalWrite(BackLeftServo, center);
  digitalWrite(FrontRightServo, center);
  digitalWrite(MiddleRightServo, center);
  digitalWrite(BackRightServo, center);

  if (LStickY >= 0)
  {
    digitalWrite(FrontLeftMotorDirection, HIGH);
    digitalWrite(MiddleLeftMotorDirection, HIGH);
    digitalWrite(BackLeftMotorDirection, HIGH);
    digitalWrite(FrontRightMotorDirection, HIGH);
    digitalWrite(MiddleRightMotorDirection, HIGH);
    digitalWrite(BackRightMotorDirection, HIGH);
    if (LStickX >= 0)
    {
      Rpower = (Rpower * degreeL);
    }
    else
    {
      Lpower = (Lpower * degreeL);
    }
  }
  else
  {
    digitalWrite(FrontLeftMotorDirection, LOW);
    digitalWrite(MiddleLeftMotorDirection, LOW);
    digitalWrite(BackLeftMotorDirection, LOW);
    digitalWrite(FrontRightMotorDirection, LOW);
    digitalWrite(MiddleRightMotorDirection, LOW);
    digitalWrite(BackRightMotorDirection, LOW);
    if (LStickX >= 0)
    {
      Lpower = (Lpower * degreeL);
    }
    else
    {
      Rpower = (Rpower * degreeL);
    }
  }
  if (RTrigger == 1)
  {
    Lpower = (Lpower / 2);
    Rpower = (Rpower / 2);
  }
  analogWrite(FrontLeftMotorPower, abs(Lpower));
  analogWrite(MiddleLeftMotorPower, abs(Lpower));
  analogWrite(BackLeftMotorPower, abs(Lpower));
  analogWrite(FrontRightMotorPower, abs(Rpower));
  analogWrite(MiddleRightMotorPower, abs(Rpower));
  analogWrite(BackRightMotorPower, abs(Rpower));
}



void TankDrive()
{
  digitalWrite(FrontLeftServo, center);
  digitalWrite(MiddleLeftServo, center);
  digitalWrite(BackLeftServo, center);
  digitalWrite(FrontRightServo, center);
  digitalWrite(MiddleRightServo, center);
  digitalWrite(BackRightServo, center);
  if (LStickY >= 0)
  {
    digitalWrite(FrontLeftMotorDirection, HIGH);
    digitalWrite(MiddleLeftMotorDirection, HIGH);
    digitalWrite(BackLeftMotorDirection, HIGH);
  }
  else
  {
    digitalWrite(FrontLeftMotorDirection, LOW);
    digitalWrite(MiddleLeftMotorDirection, LOW);
    digitalWrite(BackLeftMotorDirection, LOW);
  }
  if (RStickY >= 0)
  {
    digitalWrite(FrontRightMotorDirection, HIGH);
    digitalWrite(MiddleRightMotorDirection, HIGH);
    digitalWrite(BackRightMotorDirection, HIGH);
  }
  else
  {
    digitalWrite(FrontRightMotorDirection, LOW);
    digitalWrite(MiddleRightMotorDirection, LOW);
    digitalWrite(BackRightMotorDirection, LOW);
  }
  if (RTrigger == 1)
  {
    Lpower = (Lpower / 2);
    Rpower = (Rpower / 2);
  }
  analogWrite(FrontLeftMotorPower, abs(LStickY));
  analogWrite(MiddleLeftMotorPower, abs(LStickY));
  analogWrite(BackLeftMotorPower, abs(LStickY));
  analogWrite(FrontRightMotorPower, abs(RStickY));
  analogWrite(MiddleRightMotorPower, abs(RStickY));
  analogWrite(BackRightMotorPower, abs(RStickY));
}



void TokyoDrift()
{
  if (LStickY >= 0)
  {
    digitalWrite(FrontLeftMotorDirection, HIGH);
    digitalWrite(MiddleLeftMotorDirection, HIGH);
    digitalWrite(BackLeftMotorDirection, HIGH);
    digitalWrite(FrontRightMotorDirection, HIGH);
    digitalWrite(MiddleRightMotorDirection, HIGH);
    digitalWrite(BackRightMotorDirection, HIGH);
  }
  else
  {
    digitalWrite(FrontLeftMotorDirection, LOW);
    digitalWrite(MiddleLeftMotorDirection, LOW);
    digitalWrite(BackLeftMotorDirection, LOW);
    digitalWrite(FrontRightMotorDirection, LOW);
    digitalWrite(MiddleRightMotorDirection, LOW);
    digitalWrite(BackRightMotorDirection, LOW);
  }
  /*if(PS4->R2() == true)
    {
    magL = (magL/2);
    }*/
  Lpower = magL;
  Rpower = magL;
  digitalWrite(FrontLeftMotorPower, abs(Lpower));
  digitalWrite(MiddleLeftMotorPower, abs(Lpower));
  digitalWrite(BackLeftMotorPower, abs(Lpower));
  digitalWrite(FrontRightMotorPower, abs(Rpower));
  digitalWrite(MiddleRightMotorPower, abs(Rpower));
  digitalWrite(BackRightMotorPower, abs(Rpower));

  int angle;
  if (LStickY >= 0)
  {
    angle = map(LStickX, -255, 255, 0, 180);
  }
  else
  {
    angle = map(LStickX, -255, 255, 180, 0);
  }
  digitalWrite(FrontLeftServo, angle);
  digitalWrite(MiddleLeftServo, angle);
  digitalWrite(BackLeftServo, angle);
  digitalWrite(FrontRightServo, angle);
  digitalWrite(MiddleRightServo, angle);
  digitalWrite(BackRightServo, angle);
}



void StearingWheel()
{
  if (LStickY >= 0)
  {
    digitalWrite(FrontLeftMotorDirection, HIGH);
    digitalWrite(MiddleLeftMotorDirection, HIGH);
    digitalWrite(BackLeftMotorDirection, HIGH);
    digitalWrite(FrontRightMotorDirection, HIGH);
    digitalWrite(MiddleRightMotorDirection, HIGH);
    digitalWrite(BackRightMotorDirection, HIGH);
  }
  else
  {
    digitalWrite(FrontLeftMotorDirection, LOW);
    digitalWrite(MiddleLeftMotorDirection, LOW);
    digitalWrite(BackLeftMotorDirection, LOW);
    digitalWrite(FrontRightMotorDirection, LOW);
    digitalWrite(MiddleRightMotorDirection, LOW);
    digitalWrite(BackRightMotorDirection, LOW);
  }
  Lpower = LStickY;
  Rpower = LStickY;
  /*if(PS4->R2() == true)
    {
    Lpower = (Lpower/2);
    Rpower = (Rpower/2);
    }*/
  digitalWrite(FrontLeftMotorPower, abs(Lpower));
  digitalWrite(MiddleLeftMotorPower, abs(Lpower));
  digitalWrite(BackLeftMotorPower, abs(Lpower));
  digitalWrite(FrontRightMotorPower, abs(Rpower));
  digitalWrite(MiddleRightMotorPower, abs(Rpower));
  digitalWrite(BackRightMotorPower, abs(Rpower));

  digitalWrite(MiddleLeftServo, 90);
  digitalWrite(MiddleRightServo, 90);
  RStickX = map(RStickX, -255, 255, 0, 180);
  digitalWrite(FrontLeftServo, RStickX);
  digitalWrite(FrontRightServo, RStickX);
  RStickX = map(RStickX, -255, 255, 180, 0);
  digitalWrite(BackLeftServo, RStickX);
  digitalWrite(BackRightServo, RStickX);
}

void setup()
{
  Serial.begin(9600);
  pinMode(FrontRightMotorPower, OUTPUT);
  pinMode(MiddleRightMotorPower, OUTPUT);
  pinMode(BackRightMotorPower, OUTPUT);
  pinMode(FrontLeftMotorPower, OUTPUT);
  pinMode(MiddleLeftMotorPower, OUTPUT);
  pinMode(BackLeftMotorPower, OUTPUT);
  pinMode(FrontRightMotorDirection, OUTPUT);
  pinMode(MiddleRightMotorDirection, OUTPUT);
  pinMode(BackRightMotorDirection, OUTPUT);
  pinMode(FrontLeftMotorDirection, OUTPUT);
  pinMode(MiddleLeftMotorDirection, OUTPUT);
  pinMode(BackLeftMotorDirection, OUTPUT);
  pinMode(FrontRightServo, OUTPUT);
  pinMode(MiddleRightServo, OUTPUT);
  pinMode(BackRightServo, OUTPUT);
  pinMode(FrontLeftServo, OUTPUT);
  pinMode(MiddleLeftServo, OUTPUT);
  pinMode(BackLeftServo, OUTPUT);
}

void loop()
{
  if (Serial.available() > 7)
  {
    int numBytes = Serial.readBytes(inputs, Serial.available());
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
    if (i < numBytes - 3)
    {
      LStickX = inputs[i];
      LStickY = inputs[i + 1];
      RStickX = inputs[i + 2];
      RStickY = inputs[i + 3];
      Cross = inputs[i + 4];
      Square = inputs[i + 5];
      Circle = inputs[i + 6];
      Triangle = inputs[i + 7];
      LStickX = map(LStickX, 0, 1024, -255, 255);
      LStickY = map(LStickY, 0, 1024, -255, 255);
      RStickX = map(RStickX, 0, 1024, -255, 255);
      RStickY = map(RStickY, 0, 1024, -255, 255);
      Serial.flush();
    }
  }
  if (LStickX <= deadZone && LStickX >= -deadZone) {
    LStickX = 0;
  }
  if (LStickY <= deadZone && LStickY >= -deadZone) {
    LStickY = 0;
  }
  if (RStickX <= deadZone && RStickX >= -deadZone) {
    RStickX = 0;
  }
  if (RStickY <= deadZone && RStickY >= -deadZone) {
    RStickY = 0;
  }

  if (LStickX > endZone) {
    LStickX = 255;
  }
  if (LStickY > endZone) {
    LStickY = 255;
  }
  if (RStickX > endZone) {
    RStickX = 255;
  }
  if (RStickY > endZone) {
    RStickY = 255;
  }

  if (LStickX < -endZone) {
    LStickX = -255;
  }
  if (LStickY < -endZone) {
    LStickY = -255;
  }
  if (RStickX < -endZone) {
    RStickX = -255;
  }
  if (RStickY < -endZone) {
    RStickY = -255;
  }

  magL = sqrt(sq(LStickX) + sq(LStickY));
  magR = sqrt(sq(RStickX) + sq(RStickY));
  degreeL = atan(LStickY / LStickX);
  degreeR = atan(RStickY / RStickX);

  TankDrive();

  if(Square == 1)
    {
    driveMode = 1;
    }
    else if(Cross == 1)
    {
    driveMode = 2;
    }
    else if(Circle == 1)
    {
    driveMode = 3;
    }
    else if(Triangle == 1)
    {
    driveMode = 4;
    }

    switch (driveMode)
    {
    case 1:
    {
      LeftJoystickDrive();
    }
    case 2:
    {
      TankDrive();
    }
    case 3:
    {
      TokyoDrift();
    }
    case 4:
    {
      StearingWheel();
    }
    }
  //Serial.print(Lpower); Serial.print(" "); Serial.println(Rpower);
}
