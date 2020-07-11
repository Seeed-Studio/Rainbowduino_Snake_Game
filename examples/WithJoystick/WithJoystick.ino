#include "Rainbowduino.h"
#include "Snake.h"
Snake snake;

unsigned char PreDirect = RIGHT;
unsigned char CurDirect = RIGHT;
unsigned char PreDirect_temp1;
unsigned char CurDirect_temp1;
unsigned char PreDirect_temp;
unsigned char CurDirect_temp;
boolean Flag_Debounce = 0;
unsigned char PixelX;
unsigned char PixelY;
#define JOYSTICK_X A0
#define JOYSTICK_Y A1
//**********************************************
void GetDirection(void)
{
  int XValue = analogRead(JOYSTICK_X);
  int YValue = analogRead(JOYSTICK_Y);
  if(XValue < 400) CurDirect_temp = LEFT;
  else if(YValue < 400)CurDirect_temp = DOWN;
  else if(XValue > 600)CurDirect_temp = RIGHT;
  else if(YValue > 600)CurDirect_temp = UP;
  else return;
  if(Flag_Debounce == 0)
  {
    Flag_Debounce = 1;
    CurDirect_temp1 = CurDirect_temp;
    return;
  }
  else
  {
    if(CurDirect_temp != CurDirect_temp1)
    {
      Flag_Debounce = 0;
      return;
    }
  }
  PreDirect = CurDirect;
  CurDirect = CurDirect_temp;
  if((PreDirect + CurDirect) == 5)CurDirect = PreDirect;
}


long time_20ms  = 0;

long time_300ms = 0;
void setup()
{
 Serial.begin(9600);
  snake.init();
  
  time_20ms = millis();
  time_300ms = millis();
}



void loop()
{  
  if((millis()-time_20ms) > 20)
 {
   time_20ms = millis();
   GetDirection();
   
 } 
 if((millis()-time_300ms) > 300)
 {
   time_300ms = millis();
   Rb.blankDisplay();
  snake.SnakeMove(CurDirect);
  //Flag_300ms = false;
 }
}
