#include "DoublingMathProblem.h"

DoublingMathProblem::DoublingMathProblem(){}
void DoublingMathProblem::setProblem(Fraction f1){
   MathProblem::setProblem(f1,'+',f1);
}
