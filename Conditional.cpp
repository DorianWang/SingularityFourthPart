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

   case (NOT):
      for (int i = 0; i < Conditionals.size(); i++){
         if (Conditionals[i].checkConditional() == true){
            return false;
         }
      }
      return true;
      break;

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



template <typename T> void Conditional<T>::addComparedValue()

template <typename T> void Conditional<T>::addWatchedValue(T* watchedValue);

      void changeLogicOp(LogicOperators newOp);
      void changeValueOp(ValueOperators newOp);






