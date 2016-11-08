#include "Location.h"



Location::Location(int baseCost, int baseCycles, int baseUpkeep, int numSpaces, bool isBuildable, riskModifiers newRiskModifiers, int newX, int newY)
{
   this -> baseCost = baseCost;
   this -> baseCycles = baseCycles;
   this -> baseUpkeep = baseUpkeep;
   this -> totalSize = numSpaces;
   this -> isBuildable = isBuildable;
   this -> locationRiskModifiers = newRiskModifiers;
   this -> locationAreaX = newX;
   this -> locationAreaY = newY;
}

Location::~Location()
{
   //dtor
};

//Getters and Setters
//{

   //Getters
   //{

   std::string Location::getDescription()
   {
      return locationName; //TODO: Make description.
   }

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

   //Get Base Values
   //{
   int Location::getBaseCycles()
   {
      return baseCycles;
   }

   int Location::getBaseCost()
   {
      return baseCost;
   }

   int Location::getBaseUpkeep()
   {
      return baseUpkeep;
   }
   //}


   int Location::getTotalSize()
   {
      return totalSize;
   }

   int Location::getNumEmptySpaces()
   {
      return totalSize - containedDevices.size();
   }

   int Location::getModifier(int modifier)
   {

      std::map <int, int>::iterator it = localEffects.find(modifier);
      if (it != localEffects.end())
      {
         return localEffects.at(modifier);
      }
      else
      {
         return MODIFIER_NOT_INITIALIZED;
      }
   }

   bool Location::hasActiveModifier(int modifier)
   {
      std::map <int, int>::iterator it = localEffects.find(modifier);
      if (it != localEffects.end()){
         if(it -> second == -1 || it -> second > 0){
            return true;
         }
      }
      return false;
   }


   //}



   //Setters
   //{

   void Location::recalculate()
   {
      //Call all the functions to recalculate cycles, risk, risk modifiers, and leftover size.
      //Or do it here, it doesn't really matter.
   }

   std::list <int> Location::tick()
   {
      //There are lots of things to do in this. There may be more to do here.

      std::list <int> decayedModifiers;

      //Finds decayed modifiers and marks them. Reduces the value of modifiers which are greater than 0.
      for (auto &iter : localEffects){
         if (iter.second == 0){
            decayedModifiers.push_front(iter.first);
         }
         //Reduces modifiers
         if (iter.second > 0){ iter.second -= 1; }
      }

      //Removes decayed modifiers.
      std::list<int>::const_iterator listIterator;
      for (listIterator = decayedModifiers.begin(); listIterator != decayedModifiers.end(); ++listIterator) {
         removeModifier(*listIterator);
      }



      return decayedModifiers;
   }



   //Returns true if added, false if not.
   bool Location::addModifier(int modifier, int duration)
   {
      std::map <int, int>::iterator it = localEffects.find(modifier);
      if (it == localEffects.end() || it -> second == 0){
         localEffects[modifier] = duration;
         return true;
      }
      return false;
   }

   //Returns true if a modifier was removed, false if not.
   bool Location::removeModifier(int modifier)
   {
      std::map <int, int>::iterator it = localEffects.find(modifier);
      if (it != localEffects.end()){
         localEffects.erase(it);
         return true;
      }
      return false;
   }

   //Removes a modifier when given an iterator which is in the map.
   bool Location::removeModifier(std::map <int, int>::iterator it)
   {
      if (it != localEffects.end()){
         localEffects.erase(it);
         return true;
      }
      return false;
   }

   //Sets the selected modifier to the selected duration.
   void Location::setModifier(int modifier, int duration)
   {
      localEffects[modifier] = duration;
   }

   bool Location::addDevice(Device newDevice)
   {
      if (isBuildable && (containedDevices.size() < totalSize)){
         containedDevices.push_back(newDevice);
         return true;
      }
      return false;
   }

   bool Location::removeDevice(int deviceType)
   {
      if (isBuildable && (containedDevices.size() > 0)){
         containedDevices.f
      }
   }

   //}








//}






































