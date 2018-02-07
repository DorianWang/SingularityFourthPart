#include "Bug.h"

Bug::Bug()
{
   //ctor
   return;
}

Bug::Bug(int aproxSeverity)
{
   int weights[BUG_TYPE_NUMBER] = {0}; //All bug chances start at 0.
   if (aproxSeverity == 0){
      weights[BUG_BAD_DESIGN] = 100;
   }
   else if (aproxSeverity < 2){
      BUG_BAD_DESIGN
   }
   else if (aproxSeverity < 4){

   }
   else if (aproxSeverity < 6){

   }
   else if (aproxSeverity < 8){

   }
   else {


   }
   trueSeverity = aproxSeverity; //TODO
}

Bug::Bug(bugTypes type)

Bug::~Bug()
{
   //dtor
   return;
}
