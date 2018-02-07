#ifndef CONDITIONALBASE_H
#define CONDITIONALBASE_H


class ConditionalBase
{
   public:
      /** Default constructor */
      ConditionalBase();
      /** Default destructor */
      virtual ~ConditionalBase();
      virtual bool checkConditional() = 0;
      virtual void addConditional(ConditionalBase* input) = 0;
   protected:
   private:
};

#endif // CONDITIONALBASE_H
