#ifndef MAINLOOP_H
#define MAINLOOP_H

#include "stateStorage.h"


#define PAUSE_KEY p
//Will be changed later
#define EXIT_KEY q

class MainLoop
{
   public:
      /** Default constructor */
      MainLoop();

      /** Default destructor */
      ~MainLoop();

      /** The function that does the actual loop */
      int gameLoop();


   protected:
   private:
};

#endif // MAINLOOP_H



















