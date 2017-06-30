#ifndef TICKABLE_H
#define TICKABLE_H


class tickable
{
   public:
      /** Default constructor */
      tickable();
      /** Default destructor */
      virtual ~tickable();

      virtual bool tick() = 0;
   protected:
   private:
};

#endif // TICKABLE_H
