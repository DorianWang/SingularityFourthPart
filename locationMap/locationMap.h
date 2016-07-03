#ifndef LOCATIONMAP_H
#define LOCATIONMAP_H

#include <vector>

#include "location.h"

class locationMap
{
   public:
      locationMap();
      ~locationMap();
   protected:
   private:
      std::vector <Location> locationList;
};







#endif // LOCATIONMAP_H
