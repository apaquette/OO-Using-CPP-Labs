#ifndef MATHPROBLEM_H
#define MATHPROBLEM_H
#include "Fraction.h"

class MathProblem{
   protected:
      Fraction firstFraction;
      Fraction secondFraction;
      Fraction userAnswer;
      Fraction correctAnswer;
      char operation;
      bool isAnswerCorrect;
   public:
      void setProblem(Fraction, char, Fraction);
      MathProblem();
      void displayProblem();
      void askUserForAnswer();
      void displayResults();
      bool isCorrect();
};

#endif // MATHPROBLEM_H
