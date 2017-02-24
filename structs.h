#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

//Modifiers for the three types of risk.
// 1000 is base value, 0 is no risk, etc.
struct riskModifiers
{
   unsigned int publicModifier; // These modifiers are out of 1000. 1000 -> x1, 500 -> x0.5, 2250 -> x2.25
   unsigned int mediaModifier;
   unsigned int covertModifier;

   unsigned int risk; //The risk of being detected, multiplied by 10000. (12 = 0.12%)
};







#endif // STRUCTS_H_INCLUDED
