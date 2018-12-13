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


      void changeLogicOp(conditionalEnums::LogicOperators newOp);

      bool evaluate();


   private:
      std::vector <ConditionalBase*> Conditionals; // Array of points, to conserve memory. Remember to release conditionals when destroying.
      conditionalEnums::LogicOperators currentLogicOP;

      //T comparedValue;






};

#endif // CONDITIONAL_H
