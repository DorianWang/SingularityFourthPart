#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <map>
#include <list>
#include <vector>
#include <stdexcept>

#include "Device.h"
#include "../structs.h"


#define TINY_LOCATION 2
#define VERY_SMALL_LOCATION 4
#define SMALL_LOCATION 8
#define MEDIUM_LOCATION 16
#define LARGE_LOCATION 32
#define VERY_LARGE_LOCATION 64
#define HUGE_LOCATION 128
#define MASSIVE_LOCATION 256

#define MODIFIER_NOT_INITIALIZED -2





class Location
{
   public:
      Location(int baseCost, int baseCycles, int baseUpkeep, int numSpaces, bool isBuildable, riskModifiers newRiskModifiers, int newX, int newY);
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

      Device getDevice(int DeviceID); //Gets the device with the exact ID                                   | TODO

      std::list <Device> getDevices(int DeviceType); //Gets all devices with the same type.                 | TODO



      void recalculate(); //Recalculates the risk, cycles and cost of the location.                         | TODO: Do things with this...
      std::list <int> tick(); //Reduces the duration of modifiers, and returns expired modifiers.           | TODO: Do tick things later.

      bool addModifier(int modifier, int duration); //Adds a modifier if it doesn't already exist, or is 0. | Complete
      bool removeModifier(int modifier); //Removes a modifier, with no record of it existing.               | Complete
      bool removeModifier(std::map <int, int>::iterator it); //Removes a modifier.                          | Complete
      void setModifier(int modifier, int duration); //Overwrites.                                           | Complete


      bool addDevice(Device newDevice); //Adds the passed device to the location.                           | Complete (for now)

      bool removeDevice (unsigned long long DeviceID); // Removes the specific Device.                      | TODO
      int removeDevices (int DeviceType); // Removes all devices with the same type.                        | TODO
      std::vector <bool> removeDevices (std::vector <int> DeviceTypes); //Calls remove for each one.        | TODO


   protected:
   private:

      int baseCost; //Base cost of the location. Does not change normally.
      int baseCycles; //Base number of cycles the location provides. Does not change normally.
      int baseUpkeep; //Base amount of money required for location operation.

      bool isBuildable; //If true, allows adding or removing devices to the location.
      unsigned int totalSize; //The amount of building spots. If not buildable, it will still affect the description.

      int totalCost; //Total cost of the location. Takes into account improvements and such.
      int numCycles; //Number of cycles the location provides.

      riskModifiers locationRiskModifiers; //Risk modifiers.

      riskModifiers baseDiscoveryValue; //Base amount of Discovery this location causes, more mundane locations
                                    // cause less Discovery.

      std::map <int, int> localEffects; //These are the modifiers on the location, and the duration.

      std::list <Device> containedDevices; //The devices at the location. These provide cycles, but cost risk, upkeep and spaces.

      std::string locationName; // The displayed name of the location. This would appear on the map.

      // Where the location should be displayed on the map.
      int locationAreaX;
      int locationAreaY;

};

#endif // LOCATION_H











