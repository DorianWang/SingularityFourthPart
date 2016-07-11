#include "Location.h"


Location::Location(int baseCost, int baseCycles, int baseUpkeep, int numSpaces, bool isBuildable)
{
   this.baseCost = baseCost;
   this.baseCycles = baseCycles;
   this.baseUpkeep = baseUpkeep;
   this.totalSize = numSpaces;
   this.isBuildable = isBuildable
}

Location::~Location()
{
   //dtor
}

//Setters and Getters
//{

   //Setters
   //{








   void Location::recalculate()
   {
      //Call all the functions to recalculate cycles, risk, risk modifiers, and leftover size.
      //Or do it here, it doesn't really matter.
   }

   //}


   //Getters
   //{

   int Location::getCycles()
   {
      return numCycles;
   }

   riskModifiers Location::getRisk()
   {
      return locationRiskModifiers;
   }

   int Location::getCost()
   {
      return totalCost;
   }

   int Location::getUpkeep()
   {
      return numCycles;
   }

   //}





//}






































