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

   switch (this -> currentLogicOP){

   case (conditionalEnums::AND):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> evaluate() == false){
            return false;
         }
      }
      return true;
      break;

   case (conditionalEnums::NAND):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> evaluate() == false){
            return true;
         }
      }
      return false;
      break;

   case (conditionalEnums::OR):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> evaluate() == true){
            return true;
         }
      }
      return false;
   break;

   case (conditionalEnums::NOR):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> evaluate() == true){
            return false;
         }
      }
      return true;
   break;

   case (conditionalEnums::XOR):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> evaluate() == true){
            counter++;
         }
      }
      if (counter % 2) return true; //works best with 2 inputs, but I guess it could work with more
   break;

   case (conditionalEnums::MAJOR):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> evaluate() == true){
            counter++;
         }
      }
      if (counter > ((Conditionals.size() + 1) / 2)) return true;
   break;

   case (conditionalEnums::MINOR):
      for (i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i] -> evaluate() == true){
            counter++;
         }
      }
      if (counter < (((Conditionals.size() + 1) / 2) + 1) ) return true;
   break;

   };

   return true; //Default result, I might put an exception here.
}

template <typename T> bool Conditional<T>::evaluate()
{
   return this -> checkConditional();
}



//Setters
//{

template <typename T> void Conditional<T>::addConditional(ConditionalBase* newConditional)
{
   Conditionals.push_back(newConditional);
   return;
}


template <typename T> void Conditional<T>::changeLogicOp(conditionalEnums::LogicOperators newOp)
{
   currentLogicOP = newOp;
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


