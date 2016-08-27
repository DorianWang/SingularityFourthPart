#ifndef LOCATIONMAP_H
#define LOCATIONMAP_H

#include <vector>

#include "location.h"

class locationMap
{
   public:
      locationMap();
      ~locationMap();

      void displayMap(); //TODO: make this actually display things, or call something to display things.

   protected:
   private:
      std::vector <Location> locationList;
};







#endif // LOCATIONMAP_H
