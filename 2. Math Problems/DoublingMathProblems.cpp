#include<iostream>
#include<string>
using namespace std;
class Fraction
{
   friend ostream& operator<<(ostream&, Fraction&);
   friend istream& operator>>(istream&, Fraction&);
   private:
      int wholeNum;
      int numerator;
      int denominator;
      double convert();
   public:
      Fraction(int = 0, int = 1);
      Fraction(int, int, int);
      void enterFractionValue();
      void reduceFraction();
      void displayFraction();
      int getWholeNum();
      int getNumerator();
      void removeWholeNum();
      Fraction operator+(Fraction&);
      Fraction operator-(Fraction&);
      Fraction operator*(Fraction&);
      Fraction operator/(Fraction&);
      bool operator==(Fraction&);
      bool operator>(Fraction&);
      bool operator<(Fraction&);
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
double Fraction::convert()
{
   double floating;
   floating = numerator;
   floating = wholeNum + (floating / denominator);
   return floating;
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
   cout<<endl;
}
int Fraction::getWholeNum()
{
   return wholeNum;
}
int Fraction::getNumerator()
{
   return numerator;
}
void Fraction::removeWholeNum()
{
  numerator += wholeNum * denominator;
  wholeNum = 0;
}
Fraction Fraction::operator+(Fraction &secondFraction)
{
  int tempNum, tempDenom;
  removeWholeNum();
  secondFraction.removeWholeNum();
  tempNum = numerator * secondFraction.denominator +
	    secondFraction.numerator * denominator;
  tempDenom = denominator * secondFraction.denominator;
  Fraction result(tempNum, tempDenom);
  return result;
}
Fraction Fraction::operator-(Fraction& secondFraction)
{
  int tempNum, tempDenom;
  removeWholeNum();
  secondFraction.removeWholeNum();

  tempNum = numerator* secondFraction.denominator -
	    secondFraction.numerator * denominator;
  tempDenom = denominator * secondFraction.denominator;
  Fraction result(tempNum, tempDenom);
  return result;
}

Fraction Fraction::operator*(Fraction& secondFraction)
{
  int tempNum, tempDenom;
  removeWholeNum();
  secondFraction.removeWholeNum();

  tempNum = numerator* secondFraction.numerator;
  tempDenom = denominator * secondFraction.denominator;
  Fraction result(tempNum, tempDenom);
  return result;
}

Fraction Fraction::operator/(Fraction& secondFraction)
{
  int tempNum, tempDenom;
  removeWholeNum();
  secondFraction.removeWholeNum();

  tempNum = numerator* secondFraction.denominator;
  tempDenom = denominator * secondFraction.numerator;
  Fraction result(tempNum, tempDenom);
  return result;
}
bool Fraction::operator==(Fraction& secondFraction)
{
  bool isEqual = false;
  removeWholeNum();
  secondFraction.removeWholeNum();
  reduceFraction();
  secondFraction.reduceFraction();
  if(wholeNum == secondFraction.wholeNum && numerator == secondFraction.numerator &&
      denominator == secondFraction.denominator)
     isEqual = true;
  return isEqual;
}
bool Fraction::operator>(Fraction& frac)
{
   bool isGrtr = 0;
   double f1, f2;
   f1 = convert();
   f2 = frac.convert();
   if(f1 > f2)
      isGrtr = true;
   return isGrtr;
}
bool Fraction::operator<(Fraction& frac)
{
   bool isLess = false;
   double f1, f2;
   f1 = convert();
   f2 = frac.convert();
   if(f1 < f2)
      isLess = true;
   return isLess;
}
ostream& operator<<(ostream& out, Fraction& frac)
{
    frac.displayFraction();
    return out;
}
istream& operator>>(istream& in, Fraction& frac)
{
   frac.enterFractionValue();
   frac.reduceFraction();
   return in;
}

class MathProblem
{
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
void MathProblem::setProblem(Fraction f1, char oper, Fraction f2)
{
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
MathProblem::MathProblem()
{
   isAnswerCorrect = false;
}
void MathProblem::displayProblem()
{
   cout << firstFraction << " " << operation << " " << secondFraction << " = ? ";
}
void MathProblem::askUserForAnswer()
{
   cin >> userAnswer;
   if(userAnswer == correctAnswer)
      isAnswerCorrect = true;
}
void MathProblem::displayResults()
{
   cout << "Problem: " << firstFraction << " " << operation << " " <<
      secondFraction << endl;
   cout << "Your answer " << userAnswer;
   cout << "   Correct answer " << correctAnswer;
   if(isAnswerCorrect)
     cout << "    Correct!";
   else cout << "    Sorry, wrong answer";
   cout << endl;
}
bool MathProblem::isCorrect()
{
   return isAnswerCorrect;
}

class DoublingMathProblem : public MathProblem
{
   public:
      DoublingMathProblem();
      void setProblem(Fraction);
};
DoublingMathProblem::DoublingMathProblem()
{}
void DoublingMathProblem::setProblem(Fraction f1)
{
   MathProblem::setProblem(f1,'+',f1);
}

int main()
{
   const int NUM_PROBS = 5;
   DoublingMathProblem mp[NUM_PROBS];
   int x;
   int score = 0;
   double pct;
   for(x = 0; x < NUM_PROBS; ++x)
   {
      int randNum, randDen;
      randNum = rand() % 5;
      randNum++;
      randDen = rand() % 10;
      randDen += 5;
      Fraction f1(randNum,randDen);
      mp[x].setProblem(f1);
   }
   for(x = 0; x < NUM_PROBS; ++x)
   {
      cout<<"#"<<(x+1)<<" ";
      mp[x].displayProblem();
      mp[x].askUserForAnswer();
   }
   for(x = 0; x < NUM_PROBS; ++x)
   {
      mp[x].displayResults();
      if(mp[x].isCorrect())
         ++score;
   }
   pct = score * 100.0/NUM_PROBS;
   cout << "You answered " << pct << "% of the problems correctly." << endl;
   return 0;
}
