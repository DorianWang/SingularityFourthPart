#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <map>



#define TINY_LOCATION 2
#define VERY_SMALL_LOCATION 4
#define SMALL_LOCATION 8
#define MEDIUM_LOCATION 16
#define LARGE_LOCATION 32
#define VERY_LARGE_LOCATION 64
#define HUGE_LOCATION 128
#define MASSIVE_LOCATION 256

//Modifiers for the three types of risk.
// 1000 is base value, 0 is no risk, etc.
struct riskModifiers
{
   int publicModifier;
   int mediaModifier;
   int covertModifier;

   int risk; //The risk of being detected, multiplied by 10000. (12 = 0.12%)
};



class Location
{
   public:
      Location(int baseCost, int baseCycles, int baseUpkeep, int numSpaces, bool isBuildable);
      ~Location();

      std::string getDescription();
      void recalculate(); //Recalculates the risk, cycles and cost of the location.

      int getCycles(); //Returns the number of cycles the location provides.
      riskModifiers getRisk(); //Returns the risk of the location.
      int getCost(); //Returns the cost of the location.
      int getUpkeep(); //Returns the upkeep of the location.

      int getBaseCycles();
      int getBaseCost();
      int getBaseUpkeep();

      int getTotalSize();
      int getNumEmptySpaces();



      bool addDevice(); //TODO: Change later to actually do something.



   protected:
   private:

      int baseCost; //Base cost of the location. Does not change normally.
      int baseCycles; //Base number of cycles the location provides. Does not change normally.
      int baseUpkeep; //Base amount of money required for location operation.

      bool isBuildable;
      int totalSize; //The amount of building spots. If not buildable, it will still affect the description.


      int totalCost; //Total cost of the location. Takes into account improvements and such.
      int numCycles; //Number of cycles the location provides.

      riskModifiers locationRiskModifiers; //Risk modifiers.

      std::map <int, int> localEffects; //These are the modifiers on the location, and the duration.

      std::list <Device> containedDevices; //The devices at the location. These provide cycles, but cost risk, upkeep and spaces.
      //TODO: Change int to device.

};

#endif // LOCATION_H











