#ifndef DEVICE_H
#define DEVICE_H


class Device
{
   public:
      Device();
      virtual ~Device();
      Device(const Device& other);


   protected:
   private:

      int baseCost; //Base cost of the device. Does not change normally.
      int baseCycles; //Base number of cycles the device provides. Does not change normally.
      int baseUpkeep; //Base amount of money required for device operation.

      int deviceType; //This is the device type. Used to interact to modifiers and other devices.

      //int






};

#endif // DEVICE_H



















