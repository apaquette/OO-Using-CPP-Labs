#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
class Fraction{
   friend std::ostream& operator<<(std::ostream&, Fraction&);
   friend std::istream& operator>>(std::istream&, Fraction&);
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

#endif // FRACTION_H
