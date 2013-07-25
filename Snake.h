#ifndef SNAKE_h
#define SNAKE_h

#include "Rainbowduino.h"

#define LENGTH_MAX  20
#define UP       1
#define DOWN     4
#define LEFT     2
#define RIGHT    3

#define NOFOOD 0
#define OKFOOD 1
#define FOODCOLOR 0xFF0000 //RED
#define FOODERROR 1
#define FOODVALID 0

#define SNAKE_LEN_INIT 2
class Snake : public Rainbowduino
{
  private:
    unsigned char SnakeLength;
    unsigned char Speed;      //moving speed of the snake
    unsigned char FoodX,FoodY;//coordinate of the food
    unsigned long FoodColor;//24bit RGB
   // unsigned char *SnakeX,*SnakeY;//coordinate of the snake
    unsigned char SnakeX[LENGTH_MAX],SnakeY[LENGTH_MAX];
    unsigned long SnakeColor;//24bit RGB
    unsigned char GameOverFlag;//flag for game over:1 = over.
    unsigned char FoodFlag;//0 = No food
    unsigned char SnakeHeadX,SnakeHeadY;
//    unsigned char MoveDirection;
    
  public:
    void init(void);
    void PutFood(void);
    unsigned char WrongFood(void);
    void SnakeMove(unsigned char MoveDirection);
};
#endif
