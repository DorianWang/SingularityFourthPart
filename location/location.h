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
};



class Location
{
   public:
      Location(int baseCost, int baseCycles, );
      ~Location();

      std::string getDescription();
      void recalculate(); //Recalculates the risk, cycles and cost of the location.
      int getCycles(); //Returns the number of cycles the location provides.
      int getRisk(); //Returns the risk of the location.




   protected:
   private:

      int baseCost; //Base cost of the location. Does not change normally.
      int baseCycles; //Base number of cycles the location provides. Does not change normally.
      int baseUpkeep; //Base amount of money required for location operation.

      bool isBuildable;
      int numCycles; //Number of cycles the location provides.
      int risk; //The risk of being detected, multiplied by 10000. (12 = 0.12%)
      int totalSize; //The amount of building spots. If not buildable, it will still affect the description.


      int totalCost; //Total cost of the location. Takes into account improvements and such.

      riskModifiers locationRiskModifiers; //Risk modifiers.

      std::map <int, int> localEffects; //Theses are the modifiers on the location, and the duration.

};

#endif // LOCATION_H











