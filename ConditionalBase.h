#ifndef CONDITIONALBASE_H
#define CONDITIONALBASE_H

//XOR is # true % 2, MAJOR is at least 50%, MINOR is less than 50%
//XOR, MAJOR and MINOR are a bit more resource intensive, as they always check every one.
namespace conditionalEnums {
   enum LogicOperators{AND, NAND, OR, NOR, XOR, MAJOR, MINOR};
   enum ValueOperators{NOT_EQUAL, EQUAL, GREATER, LESSER};
}

class ConditionalBase
{
   public:
      /** Default constructor */
      ConditionalBase(unsigned int newID);

      /** Default destructor */
      virtual ~ConditionalBase();
      virtual bool checkConditional() = 0;
      virtual void addConditional(ConditionalBase* input) = 0; //Returns if the condition
      unsigned int getID(){
         return ID;
      }

   protected:
      virtual bool evaluate() = 0; //Returns if the condition stored in the object is true
      conditionalEnums::LogicOperators currentLogicOP;
      conditionalEnums::ValueOperators currentValueOp;
      int numParents = 0;
      unsigned int ID;

   private:

};














#endif // CONDITIONALBASE_H
