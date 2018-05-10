
#include <iostream>

//There was GPL things for
//Endgame:Singularity, so from what I have read, this would as well.


#include "stateStorage.h"

#include "location.h"
#include "Conditional.h"

//using namespace std;

int main()
{

   stateStorage* stateInfo = new stateStorage();

   riskModifiers testRMod; testRMod.covertModifier = 13; testRMod.mediaModifier = 104; testRMod.publicModifier = 1112;
   testRMod.risk = 100;

   Location testLocation(10, 20, 30, SMALL_LOCATION, true, testRMod, 42, 43);

   //std::cout << testLocation.getBaseCost() << " " << testLocation.getBaseCycles() << std::endl;

   //std::cout << testLocation.getBaseUpkeep() << " " << testLocation.getBaseCycles() << std::endl;

   //std::cout << testLocation.getModifier(0) << " " << testLocation.getModifier(1) << std::endl;

   //std::cout << testLocation.getTotalSize() << " " << testLocation.getNumEmptySpaces() << std::endl;

   //std::cout << testLocation.getBaseCost() << " " << testLocation.getBaseCycles() << std::endl;

   Conditional <int> testConditional(0); Conditional <int> bartestConditional(1);
   std::cout << "made a conditional " << conditionalEnums::AND << conditionalEnums::GREATER << std::endl;

   testConditional.changeValueOp(conditionalEnums::EQUAL);
   bartestConditional.changeValueOp(conditionalEnums::EQUAL);

   testConditional.changeLogicOp(conditionalEnums::AND);
   bartestConditional.changeLogicOp(conditionalEnums::AND);

   std::cout << "changed it" << std::endl;
   int a = 4; int b = 3; int c = 2;
   testConditional.addComparedValue(&a); testConditional.addWatchedValue(&b); bartestConditional.addComparedValue(&a); bartestConditional.addWatchedValue(&c);
   std::cout << testConditional.checkConditional() << std::endl;
   b = 4;
   std::cout << testConditional.checkConditional() << std::endl;

   testConditional.addConditional(&bartestConditional);

   std::cout << testConditional.checkConditional() << std::endl;
   c = 4;
   std::cout << testConditional.checkConditional() << std::endl;

   std::cout << "Hello world!" << std::endl;
   return 0;

}












