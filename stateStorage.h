
#ifndef STATESTORAGE_H_INCLUDED
#define STATESTORAGE_H_INCLUDED

//Structs
//{

typedef struct mouseInfo
{
   int x;
   int y;
   int clickType;
};

typedef struct keyInfo
{
   bool keys[256];
};

//}

class stateStorage
{
public:

   //Constructors and Destructors
   inline stateStorage();
   inline ~stateStorage();

   //Reseting functions
   inline void resetAll();

   inline void resetMouse();
   inline void resetKeyboard();
   inline void resetCurrentKey();

   //Getting functions
   inline mouseInfo getMouse();
   inline keyInfo getKeyboard();
   inline keyInfo getCurrentKey();

   //Setting functions
   //They have to be public because of outside callers.
   inline void setMouse(int xPos, int yPos, int mouseButton);
   inline void setKeyboard(char keyDown);
   inline void setCurrentKey(char keyDown);


private:







};





extern stateStorage* stateInfo;



#endif // STATESTORAGE_H_INCLUDED























