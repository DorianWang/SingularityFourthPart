
#ifndef STATESTORAGE_H_INCLUDED
#define STATESTORAGE_H_INCLUDED

#include <cstdio>
#include <cstring>

#include <map>

#define NUM_KEYS 256


//Structs
//{

typedef struct mouseInfo
{
   int x;
   int y;
   int clickType;
};

/*
typedef struct globalEffect
{
   int effectType;
   int duration; //In turns. -1 for forever.
};
*/


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
   inline void resetEffects();

   //Getting functions
   inline mouseInfo* getMouse();
   inline bool* getKeyboard();
   inline bool* getCurrentKey();
   inline std::map <int, int>* getGlobalEffects();

   //Setting functions
   inline void setMouse(int xPos, int yPos, int mouseButton);
   inline void setKeyboard(char keyDown);
   inline void setCurrentKey(char keyDown);
   inline bool addGlobalEffect(int key, int duration);
   inline void setGlobalEffects(std::map <int, int> newGlobalEffects);

private:


   mouseInfo mouseState;
   bool keyState[NUM_KEYS];
   bool currentKeyState[NUM_KEYS];
   std::map <int, int> globalEffectList;

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

   void stateStorage::resetEffects()
   {
      globalEffectList.clear();
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

   std::map <int, int> * stateStorage::getGlobalEffects()
   {
      return &globalEffectList;
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

   bool stateStorage::addGlobalEffect(int key, int duration)
   {
      bool isNewDuration = duration > globalEffectList[key];
      globalEffectList[key] = std::max(globalEffectList[key], duration);
      return isNewDuration;
   }

   void stateStorage::setGlobalEffects(std::map <int, int> newGlobalEffects)
   {
      globalEffectList = newGlobalEffects;
   }

   //}

//}


extern stateStorage* stateInfo;



#endif // STATESTORAGE_H_INCLUDED























