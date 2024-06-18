#include "ComissionedEmployee.h"

//CONSTRUCTOR
//sends the name and address to employee constructor
//uses the setters to assign given sales and commission rate
ComissionedEmployee::ComissionedEmployee(std::string newName, std::string newAddress, double newSales, double newCommRate) : Employee(newName, newAddress){
    setSales(newSales);
    setCommRate(newCommRate);
}

//SETTERS
//if sales is valid, assign sales, otherwise set to zero
void ComissionedEmployee::setSales(double newSales){
    if(ComissionedEmployee::numberIsValid(newSales)){
       sales = newSales;
    }else{
        sales = 0.0;
    }
}

//if comission rate is valid, assign rate, otherwise set to zero
void ComissionedEmployee::setCommRate(double newCommRate){
    if(ComissionedEmployee::numberIsValid(newCommRate)){
       commRate = newCommRate;
    }else{
        commRate = 0.0;
    }
}

//GETTERS
//return Employee sales
double ComissionedEmployee::getSales(){
    return sales;
}
//return Employee rate
double ComissionedEmployee::getCommRate(){
    return commRate;
}

//input validation  note: I tried having this in the Employee function but couldn't get it working
//takes a variable type and returns true if greater than or equal to zero
template<typename T>bool ComissionedEmployee::numberIsValid(T num){return (num >= 0);}

//other functions
//pay function for Comissioned Employee
//calculates pay as sales times commission rate
//sets sales to zero
//return pay
double ComissionedEmployee::pay(){
    double pay = sales*commRate;
    sales = 0.0;
    return pay;
}
