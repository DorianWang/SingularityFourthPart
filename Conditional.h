#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "Modifier.h"
#include <vector>

//XOR is # true % 2, MAJOR is at least 50%, MINOR is less than 50%
//XOR, MAJOR and MINOR has a bit more resource intensive, as they always check every one.
enum LogicOperators{NOT, AND, NAND, OR, NOR, XOR, MAJOR, MINOR};


enum ValueOperators{NOT_EQUAL, EQUAL, GREATER, LESSER};


template <typename T> class Conditional
{
   public:
      /** Default constructor */
      Conditional();
      /** Default destructor */
      virtual ~Conditional();

      bool checkConditional();
      void addConditional();

      void addLocationModifer(); //TODO: All these functions
      //void addGlobalModifer(Modifier temp);



   protected:
   private:
      std::vector <Conditional> Conditionals;

      LogicOperators currentLogicOP;
      ValueOperators currentValueOp;





};

#endif // CONDITIONAL_H