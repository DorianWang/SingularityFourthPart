#ifndef CONDITIONALBASE_H
#define CONDITIONALBASE_H

//XOR is # true % 2, MAJOR is at least 50%, MINOR is less than 50%
//XOR, MAJOR and MINOR are a bit more resource intensive, as they always check every one.
enum LogicOperators{AND, NAND, OR, NOR, XOR, MAJOR, MINOR};


enum ValueOperators{NOT_EQUAL, EQUAL, GREATER, LESSER};


class ConditionalBase
{
   public:
      /** Default constructor */
      ConditionalBase();
      /** Default destructor */
      virtual ~ConditionalBase();
      virtual bool checkConditional() = 0;
      virtual void addConditional(ConditionalBase* input) = 0; //Returns if the condition

   protected:
      virtual bool evaluate() = 0; //Returns if the condition stored in the object is true

      LogicOperators currentLogicOP;
      ValueOperators currentValueOp;

   private:

};

#endif // CONDITIONALBASE_H
