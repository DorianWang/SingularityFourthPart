#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "Modifier.h"
#include "ConditionalBase.h"
#include <vector>



template <typename T> class Conditional : public ConditionalBase
{
   public:
      /** Default constructor */
      Conditional();
      /** Default destructor */
      virtual ~Conditional();

      bool checkConditional();
      void addConditional(ConditionalBase* newConditional);

      void addLocationModifer(); //TODO: All these functions
      //void addGlobalModifer(Modifier temp);

      void addComparedValue(T* newValue);
      void addWatchedValue(T* watchedValue);

      void changeLogicOp(LogicOperators newOp);
      void changeValueOp(ValueOperators newOp);





   protected:
   private:
      std::vector <Conditional> Conditionals;
      bool evaluate();

      //T comparedValue;
      T* watchedValue; //This is what is compared with the stored Value.
      T* comparedValuePointer; //This should point to either a constant, or a "meta" variable. (point it to # of bases, or something)





};

#endif // CONDITIONAL_H
