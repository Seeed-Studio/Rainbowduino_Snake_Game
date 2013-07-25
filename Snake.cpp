#include "Snake.h"
void Snake::init(void)
{
  Rainbowduino::init();
  FoodX = 0;
  FoodY = 6;
  FoodColor = 0xFF0000;//Red food    
  Rainbowduino::setPixelXY(FoodX,FoodY,FoodColor);
  FoodFlag = OKFOOD;
  SnakeLength = SNAKE_LEN_INIT;
  SnakeX[0] = 0;
  SnakeY[0] = 2;
  SnakeX[1] = 0;
  SnakeY[1] = 1;
  SnakeHeadX = SnakeX[0];
  SnakeHeadY = SnakeY[0];
  SnakeColor = 0x00FF00;//Green snake
//  Rainbowduino::drawVerticalLine(SnakeHeadX,SnakeHeadY,SnakeLength,SnakeColor);
  GameOverFlag = 0;
}

void Snake::PutFood(void)
{
  if(FoodFlag != NOFOOD)return;//food has not been ate yet.
  else{
    while(1){
      FoodX = random(7);//random seed of 0~7
      FoodY = random(7);
      if(WrongFood())continue;
      break;
    }
  }
  Rainbowduino::setPixelXY(FoodX,FoodY,FoodColor); //Draw food.Uses 24bit RGB color Code
  FoodFlag = OKFOOD;
}

unsigned char Snake::WrongFood(void)
{
  unsigned char i;
  for(i = 0;i < SnakeLength;i ++)
  {
    if(FoodX != SnakeX[i])continue;
    else if(FoodY != SnakeY[i])continue;
    else return FOODERROR;
  }
  return FOODVALID;
}
void Snake::SnakeMove(unsigned char MoveDirection)
{
  if(GameOverFlag != 1)
  {
  Rainbowduino::setPixelXY(FoodX,FoodY,FoodColor);
  switch(MoveDirection)
  {
    case UP:
            if(SnakeHeadX == 0)SnakeHeadX = 7;
            else SnakeHeadX --;
            break;
    case DOWN:
            if(SnakeHeadX == 7)SnakeHeadX = 0;
            else SnakeHeadX ++;
            break;
    case LEFT:
            if(SnakeHeadY == 0)SnakeHeadY = 7;
            else SnakeHeadY --;
            break;
    case RIGHT:
            if(SnakeHeadY == 7)SnakeHeadY = 0;
            else SnakeHeadY ++;
            break;
    default:break;
  }
  if((SnakeHeadX == FoodX)&&(SnakeHeadY == FoodY))//snake eat the food
  {
    SnakeLength ++;
    FoodFlag = NOFOOD;
  }
  for(unsigned char i = 1; i < SnakeLength; i++)  //Snake moving
  {
            SnakeX[SnakeLength - i] = SnakeX[SnakeLength - i - 1]; 
            SnakeY[SnakeLength - i] = SnakeY[SnakeLength - i - 1]; 
   }
   SnakeX[0] = SnakeHeadX;
   SnakeY[0] = SnakeHeadY;
   PutFood();
   for(unsigned char i = 0;i < SnakeLength;i ++)//Draw the snake
   {
     Rainbowduino::setPixelXY(SnakeX[i],SnakeY[i],SnakeColor);
   }
   for(unsigned char i = 1;i < SnakeLength;i ++)//judge if snake hit itself
   {
     if((SnakeX[i] == SnakeHeadX) && (SnakeY[i] == SnakeHeadY)){
       GameOverFlag = 1;
       break;
     }
   }
   //Rainbowduino::blankDisplay();
  }
  else while(1);
}
