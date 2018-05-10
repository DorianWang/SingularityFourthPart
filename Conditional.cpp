#include "Conditional.h"

template <typename T> Conditional<T>::Conditional(unsigned int newID)
   : ConditionalBase (newID)
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

   case (conditionalEnums::AND):
      if (counter == 0) return false;
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> checkConditional() == false){
            return false;
         }
      }
      return true;
      break;

   case (conditionalEnums::NAND):
      if (counter == 0) return true;
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> checkConditional() == false){
            return true;
         }
      }
      return false;
      break;

   case (conditionalEnums::OR):
      if (counter == 1) return true;
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> checkConditional() == true){
            return true;
         }
      }
      return false;
   break;

   case (conditionalEnums::NOR):
      if (counter == 1) return false;
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> checkConditional() == true){
            return false;
         }
      }
      return true;
   break;

   case (conditionalEnums::XOR):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> checkConditional() == true){
            counter++;
         }
      }
      if (counter % 2) return true;
   break;

   case (conditionalEnums::MAJOR):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> checkConditional() == true){
            counter++;
         }
      }
      if (counter > ((Conditionals.size() + 1) / 2)) return true;
   break;

   case (conditionalEnums::MINOR):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> checkConditional() == true){
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
   if (watchedValue == NULL || comparedValuePointer == NULL) throw; // Not initialized
   switch (currentValueOp){
   case conditionalEnums::NOT_EQUAL:
      return (*watchedValue != *comparedValuePointer);

   case conditionalEnums::EQUAL:
      return (*watchedValue == *comparedValuePointer);

   case conditionalEnums::GREATER:
      return (*watchedValue > *comparedValuePointer);

   case conditionalEnums::LESSER:
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
   Conditionals.push_back(newConditional);
   return;
}

template <typename T> void Conditional<T>::addComparedValue(T* newValue)
{
   comparedValuePointer = newValue;
};

template <typename T> void Conditional<T>::addWatchedValue(T* newValue)
{
   watchedValue = newValue;
};

template <typename T> void Conditional<T>::changeLogicOp(conditionalEnums::LogicOperators newOp)
{
   currentLogicOP = newOp;
}
template <typename T> void Conditional<T>::changeValueOp(conditionalEnums::ValueOperators newOp)
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
//Because the class uses primitives, not equals and equals will not work well for floats.


