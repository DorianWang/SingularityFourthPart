#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <map>
#include <list>

#include "Device.h"


#define TINY_LOCATION 2
#define VERY_SMALL_LOCATION 4
#define SMALL_LOCATION 8
#define MEDIUM_LOCATION 16
#define LARGE_LOCATION 32
#define VERY_LARGE_LOCATION 64
#define HUGE_LOCATION 128
#define MASSIVE_LOCATION 256

#define MODIFIER_NOT_INITIALIZED -2

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
      Location(int baseCost, int baseCycles, int baseUpkeep, int numSpaces, bool isBuildable, riskModifiers newRiskModifiers);
      ~Location();

      std::string getDescription(); //Returns the description of the location.                              | TODO: Everything about the description.

      int getCycles(); //Returns the number of cycles the location provides.                                | Complete
      riskModifiers getRisk(); //Returns the risk of the location.                                          | Complete
      int getCost(); //Returns the cost of the location.                                                    | Complete
      int getUpkeep(); //Returns the upkeep cost of the location.                                           | Complete

      int getBaseCycles(); //Returns the base cycles of the location.                                       | Complete
      int getBaseCost(); //Returns the base cost of the location.                                           | Complete
      int getBaseUpkeep(); //Returns the base upkeep cost of the location.                                  | Complete

      int getTotalSize(); //Returns the number of spaces in the location.                                   | Complete
      int getNumEmptySpaces(); //Returns the number of empty spaces in the location.                        | Complete

      int getModifier(int modifier); //Returns the value of the selected modifier.                          | Complete
                                     //Returns MODIFIER_NOT_INITIALIZED if the modifier is not initialized.
      bool hasActiveModifier(int modifier); //Returns true if modifier exist and is -1 or above 0.          | Complete


      void recalculate(); //Recalculates the risk, cycles and cost of the location.                         | TODO: Do things with this...
      std::list <int> tick(); //Reduces the duration of modifiers, and returns expired modifiers.           | TODO: Do tick things later.

      bool addModifier(int modifier, int duration); //Adds a modifier if it doesn't already exist, or is 0. | Complete
      void removeModifier(int modifier); //Removes a modifier, with no record of it existing.               | Complete
      void setModifier(int modifier, int duration); //Overwrites.


      bool addDevice(Device newDevice); //Adds the passed device to the location.                           | Complete for now






   protected:
   private:

      int baseCost; //Base cost of the location. Does not change normally.
      int baseCycles; //Base number of cycles the location provides. Does not change normally.
      int baseUpkeep; //Base amount of money required for location operation.

      bool isBuildable; //If true, allows adding devices to the location.
      unsigned int totalSize; //The amount of building spots. If not buildable, it will still affect the description.

      int totalCost; //Total cost of the location. Takes into account improvements and such.
      int numCycles; //Number of cycles the location provides.

      riskModifiers locationRiskModifiers; //Risk modifiers.

      std::map <int, int> localEffects; //These are the modifiers on the location, and the duration.

      std::list <Device> containedDevices; //The devices at the location. These provide cycles, but cost risk, upkeep and spaces.

      std::string locationName;

};

#endif // LOCATION_H











