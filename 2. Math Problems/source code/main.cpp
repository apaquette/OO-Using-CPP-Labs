/******************************

Title: Assignment 2 - Doubling Math Problems
Author: Alex Paquette
Date: 09/28/2021

*******************************/
#include <iostream>
#include "Fraction.h"
#include "MathProblem.h"
#include "DoublingMathProblem.h"

using namespace std;

int main(){
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
      cout<<"\n#"<<(x+1)<<" ";
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
