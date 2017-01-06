#include "Device.h"

Device::Device()
{
   //ctor
}

Device::~Device()
{
   //dtor
}

Device::Device(const Device& other)
{
   //copy ctor
}

//Setters
//{

int Device::getBaseCost()
{
   return baseCost;
}
int Device::getbaseCycles()
{
   return baseCycles;
}
int Device::getbaseUpkeep()
{
   return baseUpkeep;
}

riskModifiers Device::getBaseRisk()
{
   return baseRisk;
}

unsigned long long Device::getDeviceID()
{
   return deviceID;
}


//}


//Getters
//{

int Device::getCost()
{
   return baseCost;
}
int Device::getCycles()
{
   return baseCycles;
}

int Device::getUpkeep()
{
   return baseUpkeep;
}

riskModifiers Device::getRisk()
{
   return baseRisk;
}

//}





















