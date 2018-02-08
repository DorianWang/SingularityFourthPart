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
   unsigned int counter = 0; unsigned int i = 0;
   if (evaluate()) counter++;
   switch (this -> currentLogicOP){

   case (AND):
      if (counter == 0) return false;
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == false){
            return false;
         }
      }
      return true;
      break;

   case (NAND):
      if (counter == 0) return true;
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == false){
            return true;
         }
      }
      return false;
      break;

   case (OR):
      if (counter == 1) return true;
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == true){
            return true;
         }
      }
      return false;
   break;

   case (NOR):
      if (counter == 1) return false;
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == true){
            return false;
         }
      }
      return true;
   break;

   case (XOR):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == true){
            counter++;
         }
      }
      if (counter % 2) return true;
   break;

   case (MAJOR):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == true){
            counter++;
         }
      }
      if (counter > ((Conditionals.size() + 1) / 2)) return true;
   break;

   case (MINOR):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == true){
            counter++;
         }
      }
      if (counter < (((Conditionals.size() + 1) / 2) + 1) ) return true;
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
      return (*watchedValue == *comparedValuePointer);

   case GREATER:
      return (*watchedValue > *comparedValuePointer);

   case LESSER:
      return (*watchedValue < *comparedValuePointer);

   default:
      //Set some sort of error...
      return false;
   }
}



//Setters
//{

template <typename T> void Conditional<T>::addConditional(ConditionalBase* newConditional)
{
   //TODO: Make this work properly
   return;
}

template <typename T> void Conditional<T>::addComparedValue(T* newValue)
{
   comparedValuePointer = newValue;
};

template <typename T> void Conditional<T>::addWatchedValue(T* watchedValue)
{
   this -> watchedValue = watchedValue;
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

template class Conditional<int>;
template class Conditional<float>;
template class Conditional<double>;
template class Conditional<short>;
template class Conditional<char>;
template class Conditional<long long int>;
template class Conditional<bool>; //Well, I guess...
//Because the class uses primitives, not equals will not work for floats.


