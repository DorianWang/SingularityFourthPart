#include "Comparison.h"

template <typename T> Comparison<T>::Comparison(unsigned int newID)
    : ConditionalBase (newID)
{
    ID = newID;
}

template <typename T> Comparison<T>::~Comparison()
{
    //dtor
}


template <typename T> void Comparison<T>::addComparedValue(T* newValue)
{
   comparedValuePointer = newValue;
};

template <typename T> void Comparison<T>::addWatchedValue(T* newValue)
{
   watchedValue = newValue;
};

//enum ValueOperators{NOT_EQUAL, EQUAL, GREATER, LESSER};
template <typename T> bool Comparison<T>::evaluate()
{
   if (watchedValue == NULL || comparedValuePointer == NULL){
      throw; // Not initialized
   }

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
      stateInfo -> addError("Failure to recognize value of currentValueOp in Comparison.");
      throw;
      return false;
   }
}


template <typename T> void Comparison<T>::changeValueOp(conditionalEnums::ValueOperators newOp)
{
   currentValueOp = newOp;
}




