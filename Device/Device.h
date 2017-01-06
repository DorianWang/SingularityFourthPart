#ifndef DEVICE_H
#define DEVICE_H


//Modifiers for the three types of risk.
// 1000 is base value, 0 is no risk, etc.
struct riskModifiers
{
   unsigned int publicModifier; // These modifiers are out of 1000. 1000 -> x1, 500 -> x0.5, 2250 -> x2.25
   unsigned int mediaModifier;
   unsigned int covertModifier;

   unsigned int risk; //The risk of being detected, multiplied by 10000. (12 = 0.12%)
};


class Device
{
   public:
      Device();
      ~Device();
      Device(const Device& copyDevice);

      int getBaseCost();
      int getbaseCycles();;
      int getbaseUpkeep();;;
      riskModifiers getBaseRisk();

      unsigned long long getDeviceID();


      //These need to be finished.
      int getCost();
      int getCycles();;
      int getUpkeep();
      riskModifiers getRisk();

   protected:
   private:

      int baseCost; //Base cost of the device. Does not change normally.
      int baseCycles; //Base number of cycles the device provides. Does not change normally.
      int baseUpkeep; //Base amount of money required for device operation.
      riskModifiers baseRisk; //Base amount of suspicion this device causes.

      riskModifiers baseDiscoveryValue; //Base amount of Discovery this device causes, more mundane devices
                                    // cause less Discovery.

      int deviceType; //This is the device type. Used to interact to modifiers and other devices.
                     //Devices can have the same type, but never the same ID. Unique devices will have unique types.


      unsigned long long deviceID; //This specific device's ID. Each one has a unique ID, which is not recycled
                           // This does mean that eventually it will run out of IDs, but it has at least 3 billion, so...






};

#endif // DEVICE_H



















