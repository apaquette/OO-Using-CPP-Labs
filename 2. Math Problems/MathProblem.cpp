#include<iostream>
#include<string>
using namespace std;
class Fraction
{
   private:
      int wholeNum;
      int numerator;
      int denominator;
   public:
      Fraction(int = 0, int = 1);
      Fraction(int, int, int);
      void enterFractionValue();
      Fraction addFractions(Fraction);
      Fraction multiplyFractions(Fraction);
      void reduceFraction();
      void displayFraction();
      int getWholeNum();
      int getNumerator();
      bool equals(Fraction);
};
Fraction::Fraction(int num, int denom)
{
   wholeNum = 0;
   numerator = num;
   if(denom != 0)
      denominator = denom;
   else
      denominator = 1;
   reduceFraction();
}
Fraction::Fraction(int whole, int num, int denom)
{
   wholeNum = whole;
   numerator = num;
   if(denom != 0)
      denominator = denom;
   else
      denominator = 1;
   reduceFraction();
}
void Fraction::enterFractionValue()
{
     cout<<"Enter the whole number part for the fraction ";
     cin>>wholeNum;
     cout<<"Enter the numerator ";
     cin>>numerator;
     cout<<"Enter a denominator ";
     cin>>denominator;
     while(denominator == 0)
     {
       cout<<"Denominator cannot be 0. Please reenter ";
       cin>>denominator;
     }
     reduceFraction();
}
void Fraction::reduceFraction()
{
   int gcd;
   int y;
   if(numerator >= denominator)
   {
     wholeNum += numerator / denominator;
     numerator = numerator % denominator;
   }
   
   gcd = 1;
   for(y = numerator; y > 0; --y) 
   {
       if(numerator % y == 0 && denominator % y == 0)
       {
         gcd = y;
         y = 0;
       }
     }
     numerator /= gcd;
     denominator /= gcd;
     if(numerator == 0)
       denominator = 1;
}
void Fraction::displayFraction()
{
     if(wholeNum == 0 && numerator == 0)
        cout<<"0";
     else
     {
       if(wholeNum != 0)
          cout<<wholeNum<<" ";
       if(numerator != 0)
          cout<<numerator<<"/"<<denominator;
      }
}
int Fraction::getWholeNum()
{
   return wholeNum;
}
int Fraction::getNumerator()
{
   return numerator;
}
Fraction Fraction::addFractions(Fraction b)
{
   Fraction tempA, tempB, newFrac;
   tempA.wholeNum = 0;
   tempB.wholeNum = 0;
   tempA.numerator = ((wholeNum * denominator) + numerator) * b.denominator;
   tempA.denominator = denominator * b.denominator;
   tempB.numerator = ((b.wholeNum * b.denominator) + b.numerator) * denominator;
   tempB.denominator = b.denominator * denominator;
   newFrac.wholeNum = 0;
   newFrac.numerator = tempA.numerator + tempB.numerator;
   newFrac.denominator = tempA.denominator;
   newFrac.reduceFraction();
   return newFrac;
}
Fraction Fraction::multiplyFractions(Fraction b)
{
   Fraction tempA, tempB, newFrac;
   tempA.wholeNum = 0;
   tempB.wholeNum = 0;
   tempA.numerator = ((wholeNum * denominator) + numerator);
   tempA.denominator = denominator;
   tempB.numerator = ((b.wholeNum * b.denominator) + b.numerator);
   tempB.denominator = b.denominator;
   newFrac.wholeNum = 0;
   newFrac.numerator = tempA.numerator * tempB.numerator;
   newFrac.denominator = tempA.denominator * tempB.denominator;
   newFrac.reduceFraction();
   return newFrac;
}
bool Fraction::equals(Fraction a)
{
      bool result = false;
      if(wholeNum == a.wholeNum && numerator == a.numerator &&
            denominator == a.denominator)
      result = true;
      return result;
}
class MathProblem
{
  private:
      Fraction operand1;
      Fraction operand2;
      Fraction correctAnswer;
      Fraction usersAnswer;
      char operation;
      bool isAnswerCorrect;
  public:
        void setProblem(Fraction, char, Fraction);
        void displayProblem();
        void askUserForAnswer();
        void displayAll();
        bool getIsCorrect();
};
void MathProblem::setProblem(Fraction op1, char operation, Fraction op2)
{
    operand1 = op1;
    operand2 = op2;
    this->operation = operation;
    if(operation == '+')
      correctAnswer = op1.addFractions(op2);
    else
      correctAnswer = op1.multiplyFractions(op2);
    isAnswerCorrect = false;
}
void MathProblem::displayProblem()
{
   operand1.displayFraction();
   cout<<" "<<operation<<" ";
   operand2.displayFraction();
   cout<<" ? ";
}
void MathProblem::askUserForAnswer()
{
   usersAnswer.enterFractionValue();
   usersAnswer.reduceFraction();
   isAnswerCorrect = usersAnswer.equals(correctAnswer);
}
void MathProblem::displayAll()
{
   displayProblem();
   cout<<endl<<"The correct answer is ";
   correctAnswer.displayFraction();
   cout<<" and the user's answer is ";
   usersAnswer.displayFraction();
   cout<<endl;
   if(isAnswerCorrect)
     cout<<" Correct!"<<endl;
   else
     cout<<" Sorry - wrong."<<endl;
}
bool MathProblem::getIsCorrect()
{
   return isAnswerCorrect;
}
int main()
{
   const int SZ = 5;
   Fraction fracs[6] = {Fraction(1, 2), Fraction(2, 3), Fraction (1, 4),
         Fraction(3,4), Fraction(1, 3), Fraction(1,5)};
   MathProblem mp[SZ];
   int numRight = 0;
   int x;
   mp[0].setProblem(fracs[0], '+', fracs[1]);
   mp[1].setProblem(fracs[1], '+', fracs[2]);
   mp[2].setProblem(fracs[2], '+', fracs[3]);
   mp[3].setProblem(fracs[3], '*', fracs[4]);
   mp[4].setProblem(fracs[4], '*', fracs[5]);
   for(x = 0; x < SZ; ++x)
   {
      mp[x].displayProblem();
      mp[x].askUserForAnswer();
   }
   for(x = 0; x < SZ; ++x)
   {
      mp[x].displayAll();
      if(mp[x].getIsCorrect())
         numRight++;
   }
   cout<<"You got "<<(numRight * 1.0 / SZ * 100)<<"% correct"<<endl;
   return 0;
}
