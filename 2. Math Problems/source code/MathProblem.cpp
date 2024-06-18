#include "MathProblem.h"

void MathProblem::setProblem(Fraction f1, char oper, Fraction f2){
   firstFraction = f1;
   secondFraction = f2;
   operation = oper;
   if (oper == '+')
  	correctAnswer = firstFraction + secondFraction;
   else if (oper == '-')
  	correctAnswer = firstFraction - secondFraction;
   else if (oper == '*')
  	correctAnswer = firstFraction * secondFraction;
   else correctAnswer = firstFraction / secondFraction;
   isAnswerCorrect = false;
}
MathProblem::MathProblem(){
   isAnswerCorrect = false;
}
void MathProblem::displayProblem(){
   std::cout << firstFraction << " " << operation << " " << secondFraction << " = ? ";
}
void MathProblem::askUserForAnswer(){
   std::cin >> userAnswer;
   if(userAnswer == correctAnswer)
      isAnswerCorrect = true;
}
void MathProblem::displayResults(){
   std::cout << "Problem: " << firstFraction << " " << operation << " " <<
      secondFraction << std::endl;
   std::cout << "Your answer " << userAnswer;
   std::cout << "   Correct answer " << correctAnswer;
   if(isAnswerCorrect)
     std::cout << "    Correct!";
   else std::cout << "    Sorry, wrong answer";
   std::cout << std::endl;
}
bool MathProblem::isCorrect(){
   return isAnswerCorrect;
}
