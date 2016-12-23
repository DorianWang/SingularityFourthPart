#ifndef DEVICE_H
#define DEVICE_H


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

      int getCost();
      int getCycles();;
      int getUpkeep();
      riskModifiers getRisk();

   protected:
   private:

      int baseCost; //Base cost of the device. Does not change normally.
      int baseCycles; //Base number of cycles the device provides. Does not change normally.
      int baseUpkeep; //Base amount of money required for device operation.

      int deviceType; //This is the device type. Used to interact to modifiers and other devices.
                     //Devices can have the same type, but never the same ID. Unique devices will have unique types.

      unsigned long long deviceID; //This specific device's ID. Each one has a unique ID, which is not recycled
                           // This does mean that eventually it will run out of IDs, but it has at least 3 billion, so...






};

#endif // DEVICE_H



















