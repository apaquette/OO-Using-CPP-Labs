#include "HourlyEmployee.h"

//CONSTRUCTOR
//sends the name and address to employee constructor
//uses the setters to assign given hours and hourly rate
HourlyEmployee::HourlyEmployee(std::string newName, std::string newAddress, double newHours, double newHourlyRate) : Employee(newName, newAddress){
    setHours(newHours);
    setHourlyRate(newHourlyRate);
}

//SETTERS
//if hours is valid, assign hours, otherwise set to zero
void HourlyEmployee::setHours(double newHours){
    if(numberIsValid<double>(newHours)){
       hours = newHours;
    }else{
        hours = 0;
    }
}
//if hourly rate is valid, assign rate, otherwise set to zero
void HourlyEmployee::setHourlyRate(double newHourlyRate){
    if(HourlyEmployee::numberIsValid(newHourlyRate)){
       hourlyRate = newHourlyRate;
    }else{
        hourlyRate = 0;
    }
}

//GETTERS
//return Employee Hours
double HourlyEmployee::getHours(){
    return hours;
}

//return Employee Hourly Rate
double HourlyEmployee::getHourlyRate(){
    return hourlyRate;
}

//input validation  note: I tried having this in the Employee function but couldn't get it working
//takes a variable type and returns true if greater than or equal to zero
template<typename T>bool HourlyEmployee::numberIsValid(T num){return (num >= 0);}

//other functions
//pay function for Hourly Employee
//calculates pay as hourlyRate times hours
//sets hours to zero
//return pay
double HourlyEmployee::pay(){
    double pay = hourlyRate*hours;
    hours = 0;
    return pay;
}
