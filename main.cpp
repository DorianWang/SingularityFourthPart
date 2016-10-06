
#include <iostream>

//There was a GPL licence for Endgame:Singularity, so from what I have read, this would as well.


#include "stateStorage.h"

#include "location.h"

//using namespace std;

int main()
{

   stateStorage* stateInfo = new stateStorage();

   riskModifiers testRMod; testRMod.covertModifier = 13; testRMod.mediaModifier = 104; testRMod.publicModifier = 1112;
   testRMod.risk = 100;

   Location testLocation(10, 20, 30, SMALL_LOCATION, true, testRMod, 42, 43);

   std::cout << testLocation.getBaseCost() << " " << testLocation.getBaseCycles() << std::endl;

   //std::cout << "Hello world!" << std::endl;
   return 0;

}












