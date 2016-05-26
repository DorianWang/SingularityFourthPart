
#ifndef STATESTORAGE_H_INCLUDED
#define STATESTORAGE_H_INCLUDED

#include <cstdio>
#include <cstring>

#define NUM_KEYS 256


//Structs
//{

typedef struct mouseInfo
{
   int x;
   int y;
   int clickType;
};

typedef struct globalEffect
{
   int effectType;
   int duration; //In turns. -1 for forever.
};



//}

class stateStorage
{
public:

   int numKeys;

   //Constructors and Destructors
   inline stateStorage();
   inline ~stateStorage();

   //Reseting functions
   inline void resetAll();

   inline void resetMouse();
   inline void resetKeyboard();
   inline void resetCurrentKey();

   //Getting functions
   inline mouseInfo* getMouse();
   inline bool* getKeyboard();
   inline bool* getCurrentKey();

   //Setting functions
   inline void setMouse(int xPos, int yPos, int mouseButton);
   inline void setKeyboard(char keyDown);
   inline void setCurrentKey(char keyDown);


private:


   mouseInfo mouseState;
   bool keyState[NUM_KEYS];
   bool currentKeyState[NUM_KEYS];
   std::list <globalEffect> globalEffectList;

};


//Implementation
//{

   //Constructor and Destructor
   //{

   stateStorage::stateStorage()
   {
      numKeys = NUM_KEYS;
      resetAll();
   }

   stateStorage::~stateStorage()
   {
      resetAll();
   }

   //}


   //Reseting functions
   //{

   void stateStorage::resetAll()
   {
      resetMouse();
      resetKeyboard();
      resetCurrentKey();
   }

   void stateStorage::resetMouse()
   {
      mouseState.x = 0; mouseState.y = 0; mouseState.clickType = 0;
   }

   void stateStorage::resetKeyboard()
   {
      memset(keyState, 0, numKeys);
   }

   void stateStorage::resetCurrentKey()
   {
      memset(currentKeyState, 0, numKeys);
   }

   //}


   //Getting functions
   //{

   mouseInfo* stateStorage::getMouse()
   {
      return &mouseState;
   }

   bool* stateStorage::getKeyboard()
   {
      return keyState;
   }

   bool* stateStorage::getCurrentKey()
   {
      return currentKeyState;
   }

   //}


   //Setting functions
   //{

   void stateStorage::setMouse(int xPos, int yPos, int mouseButton)
   {
      mouseState.x = xPos; mouseState.y = yPos; mouseState.clickType = mouseButton;
   }

   void stateStorage::setKeyboard(char keyDown)
   {
      keyState[keyDown] = true;
   }

   void stateStorage::setCurrentKey(char keyDown)
   {
      resetCurrentKey();
      currentKeyState[keyDown] = true;
   }

   //}

//}


extern stateStorage* stateInfo;



#endif // STATESTORAGE_H_INCLUDED























