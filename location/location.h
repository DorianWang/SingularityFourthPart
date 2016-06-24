#ifndef LOCATION_H
#define LOCATION_H


#define TINY_LOCATION 2
#define VERY_SMALL_LOCATION 4
#define SMALL_LOCATION 8
#define MEDIUM_LOCATION 16
#define LARGE_LOCATION 32
#define VERY_LARGE_LOCATION 64
#define HUGE_LOCATION 128
#define MASSIVE_LOCATION 256


class Location
{
   public:
      Location();
      ~Location();
   protected:
   private:

      bool isBuildable;
      int numCycles; //Number of cycles the location provides.
      int risk; //The risk of being detected, multiplied by 10000. (12 = 0.12%)
      int totalSize; //The amount of building spots. If not buildable, it will still affect the description.

};

#endif // LOCATION_H
