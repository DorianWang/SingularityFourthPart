#ifndef CONDITIONPARSER_H
#define CONDITIONPARSER_H

#include <vector>
#include <map>
#include <string>
#include <exception>

class ConditionParser
{
   public:
      /** Default constructor */
      ConditionParser();
      /** Default destructor */
      virtual ~ConditionParser();

      std::vector <std::string> symbolsList;
      std::map <std::string, int> symbolsMap;

      int variableNameToSymbol(std::string varName);


   protected:
   private:
};

#endif // CONDITIONPARSER_H
