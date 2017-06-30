#include "Conditional.h"

template <typename T> Conditional<T>::Conditional()
{
   //ctor
}

template <typename T> Conditional<T>::~Conditional()
{
   //dtor
}


//enum LogicOperators(AND, NAND, OR, NOR, XOR, MAJOR, MINOR)
template <typename T> bool Conditional<T>::checkConditional()
{
   int counter = 0;
   switch (currentLogicOP){

   case (AND):
      for (int i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == false){
            return false;
         }
      }
      return true;
      break;

   case (NAND):
      for (int i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == false){
            return true;
         }
      }
      return false;
      break;

   case (OR):
      for (int i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == true){
            return true;
         }
      }
      return false;
   break;

   case (NOR):
      if (evaluate()){
         return false;
      }
      for (int i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == true){
            return false;
         }
      }
      return true;
   break;

   case (XOR):
      counter = 0;
      for (int i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == true){
            counter++;
         }
      }
      if (counter % 2) return true;
   break;

   case (MAJOR):
      counter = 0;
      for (int i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == true){
            counter++;
         }
      }
      if (counter > (Conditionals.size() / 2)) return true;
   break;

   case (MINOR):
      counter = 0;
      for (int i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == true){
            counter++;
         }
      }
      if (counter < ((Conditionals.size()+1) / 2)) return true;
   break;

   };

   return true; //Default result, I might put an exception here.
}

//enum ValueOperators{NOT_EQUAL, EQUAL, GREATER, LESSER};
template <typename T> bool Conditional<T>::evaluate()
{
   switch (currentLogicOP){
   case NOT_EQUAL:
      return (*watchedValue != *comparedValuePointer);

   case EQUAL:
      return (*watchedValue == *comparedValuePointer)



      break;
   case GREATER:




      break;

   case LESSER:




      break;

   default:
      //Set some sort of error...

   }
}



//Setters
//{

template <typename T> void Conditional<T>::addComparedValue(T* newValue)
{
   comparedValuePointer = newValue;
};

template <typename T> void Conditional<T>::addWatchedValue(T* watchedValue)
{
   this.watchedValue = watchedValue;
};

template <typename T> void Conditional<T>::changeLogicOp(LogicOperators newOp)
{
   currentLogicOP = newOp;
}
template <typename T> void Conditional<T>::changeValueOp(ValueOperators newOp)
{
   currentValueOp = newOp;
}


//}
//End Setters


