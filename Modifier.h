#ifndef MODIFIER_H
#define MODIFIER_H

#include "structs.h"


class Modifier
{
   protected:
      unsigned long long modifierId;
      long long remainingDuration;

   public:
      Modifier();
      virtual ~Modifier();

      unsigned long long getID(){ return modifierId; };
      virtual riskModifiers getRiskModifiers() = 0;
      virtual unsigned int getTags() = 0;
      virtual unsigned int getCostScaling() = 0;
      virtual unsigned int getDuration() = 0;



};

#endif // MODIFIER_H
