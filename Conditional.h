#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "Modifier.h"
#include "ConditionalBase.h"
#include <vector>

#include <iostream>

template <typename T> class Conditional : public ConditionalBase
{
   public:
      /** Default constructor */
      Conditional(unsigned int newID);
      /** Default destructor */
      virtual ~Conditional();

      bool checkConditional();
      void addConditional(ConditionalBase* newConditional);

      void addLocationModifer(); //TODO: All these functions
      //void addGlobalModifer(Modifier temp);

      void addComparedValue(T* newValue);
      void addWatchedValue(T* watchedValue);

      void changeLogicOp(conditionalEnums::LogicOperators newOp);
      void changeValueOp(conditionalEnums::ValueOperators newOp);
      bool evaluate();


   private:
      std::vector <ConditionalBase*> Conditionals; // Array of points, to conserve memory. Remember to release conditionals when destroying.


      //T comparedValue;
      T* watchedValue; //This is what is compared with the stored Value.
      T* comparedValuePointer; //This should point to either a constant, or a "meta" variable. (point it to # of bases, or something)





};

#endif // CONDITIONAL_H
