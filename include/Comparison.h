#ifndef COMPARISON_H
#define COMPARISON_H

#include "../ConditionalBase.h"
#include "../stateStorage.h"

#include <vector>
#include <iostream>


template <typename T> class Comparison : public ConditionalBase
{
    public:
        Comparison(unsigned int newID);
        virtual ~Comparison();


        void addComparedValue(T* newValue);
        void addWatchedValue(T* newValue);

        void changeValueOp(conditionalEnums::ValueOperators newOp);

        bool evaluate();

    protected:

    private:
      T* watchedValue; //This is what is compared with the stored Value.
      T* comparedValuePointer; //This should point to either a constant, or a "meta" variable. (point it to # of bases, or something)
      conditionalEnums::ValueOperators currentValueOp;

};

#endif // COMPARISON_H
