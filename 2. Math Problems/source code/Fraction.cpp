#include "Fraction.h"

Fraction::Fraction(int num, int denom){
   wholeNum = 0;
   numerator = num;
   if(denom != 0)
      denominator = denom;
   else
      denominator = 1;
   reduceFraction();
}
Fraction::Fraction(int whole, int num, int denom){
   wholeNum = whole;
   numerator = num;
   if(denom != 0)
      denominator = denom;
   else
      denominator = 1;
   reduceFraction();
}
void Fraction::enterFractionValue(){
     std::cout<<"\n\nEnter the whole number part for the fraction ";
     std::cin>>wholeNum;
     std::cout<<"\nEnter the numerator ";
     std::cin>>numerator;
     std::cout<<"\nEnter a denominator ";
     std::cin>>denominator;
     while(denominator == 0){
      std::cout<<"\nDenominator cannot be 0. Please re-enter ";
      std::cin>>denominator;
     }
    reduceFraction();
}
void Fraction::reduceFraction(){
   int gcd;
   int y;
   if(numerator >= denominator){
     wholeNum += numerator / denominator;
     numerator = numerator % denominator;
   }

   gcd = 1;
   for(y = numerator; y > 0; --y){
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
double Fraction::convert(){
   double floating;
   floating = numerator;
   floating = wholeNum + (floating / denominator);
   return floating;
}
void Fraction::displayFraction()
{
   if(wholeNum == 0 && numerator == 0)
      std::cout<<"0";
   else{
      if(wholeNum != 0)
         std::cout<<wholeNum<<" ";
      if(numerator != 0)
         std::cout<<numerator<<"/"<<denominator;
   }
   std::cout<<std::endl;
}
int Fraction::getWholeNum(){
   return wholeNum;
}
int Fraction::getNumerator(){
   return numerator;
}
void Fraction::removeWholeNum(){
  numerator += wholeNum * denominator;
  wholeNum = 0;
}
Fraction Fraction::operator+(Fraction &secondFraction){
  int tempNum, tempDenom;
  removeWholeNum();
  secondFraction.removeWholeNum();
  tempNum = numerator * secondFraction.denominator +
	    secondFraction.numerator * denominator;
  tempDenom = denominator * secondFraction.denominator;
  Fraction result(tempNum, tempDenom);
  return result;
}
Fraction Fraction::operator-(Fraction& secondFraction){
  int tempNum, tempDenom;
  removeWholeNum();
  secondFraction.removeWholeNum();

  tempNum = numerator* secondFraction.denominator -
	    secondFraction.numerator * denominator;
  tempDenom = denominator * secondFraction.denominator;
  Fraction result(tempNum, tempDenom);
  return result;
}

Fraction Fraction::operator*(Fraction& secondFraction){
  int tempNum, tempDenom;
  removeWholeNum();
  secondFraction.removeWholeNum();

  tempNum = numerator* secondFraction.numerator;
  tempDenom = denominator * secondFraction.denominator;
  Fraction result(tempNum, tempDenom);
  return result;
}

Fraction Fraction::operator/(Fraction& secondFraction){
  int tempNum, tempDenom;
  removeWholeNum();
  secondFraction.removeWholeNum();

  tempNum = numerator* secondFraction.denominator;
  tempDenom = denominator * secondFraction.numerator;
  Fraction result(tempNum, tempDenom);
  return result;
}
bool Fraction::operator==(Fraction& secondFraction){
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
bool Fraction::operator>(Fraction& frac){
   bool isGrtr = 0;
   double f1, f2;
   f1 = convert();
   f2 = frac.convert();
   if(f1 > f2)
      isGrtr = true;
   return isGrtr;
}
bool Fraction::operator<(Fraction& frac){
   bool isLess = false;
   double f1, f2;
   f1 = convert();
   f2 = frac.convert();
   if(f1 < f2)
      isLess = true;
   return isLess;
}
std::ostream& operator<<(std::ostream& out, Fraction& frac){
    frac.displayFraction();
    return out;
}
std::istream& operator>>(std::istream& in, Fraction& frac)
{
   frac.enterFractionValue();
   frac.reduceFraction();
   return in;
}
