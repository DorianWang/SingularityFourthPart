#include "ConditionParser.h"

ConditionParser::ConditionParser()
{
   //ctor
}

ConditionParser::~ConditionParser()
{
   //dtor
}



int ConditionParser::variableNameToSymbol(std::string varName)
{
   try{
      int returnVal;
      returnVal = symbolsMap.find(varName);
      returnVal = symbolsMap.at(varName);
      return returnVal;
   }
   catch(ex)
   {
      //Add to list of symbols
   }
}





