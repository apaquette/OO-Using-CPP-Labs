#ifndef DOUBLINGMATHPROBLEM_H_INCLUDED
#define DOUBLINGMATHPROBLEM_H_INCLUDED
#include "MathProblem.h"

class DoublingMathProblem : public MathProblem{
   public:
      DoublingMathProblem();
      void setProblem(Fraction);
};

#endif // DOUBLINGMATHPROBLEM_H_INCLUDED
