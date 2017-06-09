#ifndef BUG_H
#define BUG_H

#include <string>
#include <stdlib.h>


#define BUG_TYPE_NUMBER 8
enum bugTypes {BUG_OVERFLOW, BUG_UNDERFLOW, BUG_OVERREAD, BUG_UNSANITIZED_INPUT, BUG_RACE_CONDITION,
                  BUG_LOGIC_ERROR, BUG_BAD_DESIGN, BUG_BACKDOOR}; //Maybe more flavour?
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









