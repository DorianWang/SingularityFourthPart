
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <ctime>

#define GLFW_INCLUDE_GLU
#include "GL\glfw3.h"

#include "UsefulHeaders.h"


#include "stringFunctions.h"
#include "eventLog.h"
#include "StatReader.h"

//MUSIC! http://www.youtube.com/watch?v=nDyzVV_e7WM&list=LL5I3vUh2iNfQ3pCU3sodYRA&shuffle=167714

eventRecorder::eventLog* eventLogger = new eventRecorder::eventLog(DEBUG_MODE);

//using namespace std;

struct interactObject
{
   std::string nameObject;
   int objectType;
   int objectAlignment; //what it is (hostile, friendly, neutral, etc)
   int numUse;
   int specialType;//normally 0, different for other things
};

struct tile
{
   char tileSymbol;
   interactObject tileEntities;
   int xCoord;
   int yCoord;
};

struct tester
{
int a;
int b;
int c;
int d;
char e;
char f;
};

#include "Bases.h"


#include "libraryIncluder.h"

//#include "D:\Dorian's programs\UsefulLibraries\Libraries\FileIO\FileIO.h"


// global variables
#define VERSION_NUM 0.01




//Keypress keyIO;
bool cursorVisibility = false;
bool cursorSmall = true;



void error_callback(int error, const char* description)
{
   //TODO: Add connection to logger here.
   //fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}


int openGLTest()
{
   if ( !glfwInit() )
      return 0; // Something bad happened...

   glfwSetErrorCallback(error_callback);

   GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);

   if ( !window ){
      glfwTerminate();
      return 0;
   }

   glfwMakeContextCurrent(window);
   glfwSetKeyCallback(window, key_callback);
   glfwSwapInterval(1); //Set time between buffer switches.

   double time = glfwGetTime();

   while (!glfwWindowShouldClose(window))
   {
      // Keep running, this defines what happens when someone uses alt-f4 or the close button on the window.
      float ratio;
      int width, height;
      glfwGetFramebufferSize(window, &width, &height);
      ratio = width / (float) height;
      glViewport(0, 0, width, height);
      glClear(GL_COLOR_BUFFER_BIT);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
      glBegin(GL_TRIANGLES);
      glColor3f(1.f, 0.f, 0.f);
      glVertex3f(-0.6f, -0.4f, 0.f);
      glColor3f(0.f, 1.f, 0.f);
      glVertex3f(0.6f, -0.4f, 0.f);
      glColor3f(0.f, 0.f, 1.f);
      glVertex3f(0.f, 0.6f, 0.f);
      glEnd();

      glfwSwapBuffers(window);
      glfwPollEvents();
   }

   glfwDestroyWindow(window);
   glfwTerminate(); //All done.
   return 1;
}





int main(int argc, char *argv[])
{
   srand (time(NULL));


   FileIO myFile;//FileIO has been tested, and appears to work...
   //However, there is more testing to be done!






std::string folderStuff = "Stuff\\";
std::string folderStuffs = "asdfasdf";

std::string tempNameFolder = "asdfasdf";

int counters = 0;


   linkedList <int> Aso();
//
ConsoleOptions testConsole;


int screenX = 158; int screenY = 61;
testConsole.setConsoleSize(screenX, screenY);
testConsole.changeCurrentWindowText("New name!");


Keypress KeyIO;




//the backslash n creates a gap.
std::string stringFuncTester = "qwerty.asdf.qwerty....This is a line break!\n....ytr.poi.";

stringFunc stringTest;



   time_t timer; struct tm* ptm; char cStr[22];
   timer = time(NULL);
   ptm = localtime (&timer);
   strftime(cStr, 20, "%F", ptm);
   //http://www.cplusplus.com/reference/ctime/strftime/

srand (static_cast <unsigned> (time(0)));

testConsole.cursorOptions.setColour(15, 0);

cout << "Testing colours" << endl;

/*
std::string testingSub = "qwertyuiop";
cout << (testingSub.substr(0, 6) == "qwerty") << endl;
//This is true.
*/

   system("PAUSE");
   system ("CLS");
   cout << "Testing OpenGL!" << endl;


   //openGLTest();


   testConsole.cursorOptions.changeCursorPos(0, 54);


   cout<<"I'm done!"<<endl;
   system("PAUSE");

   eventLogger -> addNewLog("End Program successfully!");
   eventLogger -> pushBuffer();

   return EXIT_SUCCESS;
}















