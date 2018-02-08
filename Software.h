#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "Bug.h"
#include <vector>

class Software
{
   public:
      /** Default constructor */
      Software();
      /** Default destructor */
      virtual ~Software();

      std::string getName();
      std::string getCreatorName();
      unsigned int getSize();
      int getSoftwareType();
      std::vector <Bug> getBugs();

   protected:
   private:
      std::string name;
      std::string creatorName;
      unsigned int softwareSize; // Size in what? Should I use "Quads" or "Gigs" or KBs?
                                 //I'll probably go with x100 for decimals.
      int softwareType; // What the software does, I might switch this to an enum.


      std::vector <Bug> bugList;
};

#endif // SOFTWARE_H
