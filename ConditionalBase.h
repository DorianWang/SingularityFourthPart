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
      virtual void addConditional(ConditionalBase* input) = 0; //Must be implemented
      unsigned int getID(){
         return ID;
      }

      virtual bool evaluate() = 0; //Returns true if the conditional is true

   protected:

      int numParents = 0;
      unsigned int ID;

   private:

};

class ConstConditional : ConditionalBase
{
   bool constValue;
   public:
      ConstConditional(unsigned int newID, bool constCondition) : ConditionalBase (newID){
         constValue = constCondition;
         ID = newID;
      };
      void addConditional(ConditionalBase* input){
         ; //Don't do anything, it won't be evaluated
      }
      bool evaluate(){
         return constValue;
      }
};












#endif // CONDITIONALBASE_H
