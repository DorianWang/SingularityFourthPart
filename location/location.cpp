#include "Location.h"



Location::Location(int baseCost, int baseCycles, int baseUpkeep, int numSpaces, bool isBuildable, riskModifiers newRiskModifiers)
{
   this -> baseCost = baseCost;
   this -> baseCycles = baseCycles;
   this -> baseUpkeep = baseUpkeep;
   this -> totalSize = numSpaces;
   this -> isBuildable = isBuildable;
   this -> locationRiskModifiers = newRiskModifiers;
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

   bool Location::addDevice(Device newDevice)
   {
      if (isBuildable && containedDevices.size() < totalSize){
         containedDevices.push_back(newDivice);
         return true;
      }
      return false;
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

   std::string Location::getDescription()
   {
      return locationName; //TODO: Make description.
   }

   //}





//}






































