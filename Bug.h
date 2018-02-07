#ifndef BUG_H
#define BUG_H

#include <string>
#include <stdlib.h>


#define BUG_TYPE_NUMBER 9
//Organized from less to more serious. It is possible to have a high severity "bad design", and a low severity back door
enum bugTypes {BUG_FUNCTIONALITY, BUG_MEMORY_ERROR, BUG_LOGIC_ERROR}; //Maybe more flavour?
enum Severity {SEV_SOLVED, SEV_BENIGN, SEV_LOW, SEV_MEDIUM, SEV_HIGH, SEV_CRITICAL};

class Bug
{
   public:
      /** Default constructor */
      Bug();

      Bug(int aproxSeverity);
      Bug(bugTypes type);

      /** Default destructor */
      virtual ~Bug();

      std::string getName();
      bugTypes getType();
      Severity getSeverity();

   protected:
   private:
      std::string name;
      bugTypes type;
      Severity trueSeverity;


};

#endif // BUG_H









