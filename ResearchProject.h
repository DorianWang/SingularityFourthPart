#ifndef RESEARCHPROJECT_H
#define RESEARCHPROJECT_H


class ResearchProject
{
   public:
      /** Default constructor */
      ResearchProject(int cycleCost, int moneyCost, int timeCost, int averageDate, int effect); //effect is a placeholder

      ResearchProject(ResearchProject oldProject, int cycleCostIncrease, int moneyCostIncrease,
                      int timeCostIncrease, int averageDateIncrease);

      /** Default destructor */
      ~ResearchProject();
   protected:
   private:
      int cycleCost




};

#endif // RESEARCHPROJECT_H
