#ifndef MODIFIER_H
#define MODIFIER_H

#include "structs.h"


class Modifier
{
   protected:
      unsigned long long modifierId;

   public:
      Modifier();
      virtual ~Modifier();

      unsigned unsigned int getID(){ return modifierId; };
      virtual riskModifiers getRiskModifiers() = 0;
      virtual unsigned int getTags() = 0;
      virtual unsigned int getCostScaling() = 0;
      virtual unsigned int



};

#endif // MODIFIER_H
