#include "MainLoop.h"

//Constructors and Destructors
//{

MainLoop::MainLoop()
{
   //ctor
}

MainLoop::~MainLoop()
{
   //dtor
}

//}


int MainLoop::gameLoop()
{
   bool isPaused = false;
   while (true){
      if (isPaused == false){
         //Time tick everything that ticks
      }
      if (stateInfo.getKeyboard()[PAUSE_KEY] == true){
         isPaused = true;
      }

      else if (stateInfo.getKeyboard()[EXIT_KEY] == true){
         isPaused = true;
      }
      else {;}



   }
}




















