#include "SalariedEmployee.h"
//CONSTRUCTOR
//sends the name and address to employee constructor
//uses the setters to assign given salary and weeks
SalariedEmployee::SalariedEmployee(std::string newName, std::string newAddress, double newSalary, int newWeeks) : Employee(newName, newAddress){
    setSalary(newSalary);
    setWeeks(newWeeks);
}

//SETTERS
//if salary is valid, assign salary, otherwise set to zero
void SalariedEmployee::setSalary(double newSalary){
    if(SalariedEmployee::numberIsValid(newSalary)){
       salary = newSalary;
    }else{
        salary = 0;
    }
}

//if weeks is valid, assign weeks, otherwise set to zero
void SalariedEmployee::setWeeks(int newWeeks){
    if(SalariedEmployee::numberIsValid(newWeeks)){
       weeks = newWeeks;
    }else{
        weeks = 0;
    }
}

//GETTERS
//return Employee salary
double SalariedEmployee::getSalary(){
    return salary;
}

//return Employee weeks
int SalariedEmployee::getWeeks(){
    return weeks;
}

//input validation  note: I tried having this in the Employee function but couldn't get it working
//takes a variable type and returns true if greater than or equal to zero
template<typename T>bool SalariedEmployee::numberIsValid(T num){return (num >= 0);}

//other functions
//pay function for Salaried Employee
//calculates pay as weeks times salary
//sets weeks to zero
//return pay
double SalariedEmployee::pay(){
    double pay = salary*weeks;
    weeks = 0;
    return pay;
}
