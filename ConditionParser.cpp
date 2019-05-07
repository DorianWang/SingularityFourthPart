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
      returnVal = symbolsMap.find(varName) -> second;
      returnVal = symbolsMap.at(varName);
      return returnVal;
   }
   catch(std::exception& e)
   {
      //Add to list of symbols
   }
}





