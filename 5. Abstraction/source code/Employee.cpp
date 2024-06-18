#include "Employee.h"

//CONSTRUCTOR
//uses the setters to assign given name and address
Employee::Employee(std::string newName, std::string newAddress){
    setName(newName);
    setAddress(newAddress);
}

//SETTERS
//sets the Employee name to given name
void Employee::setName(std::string newName){
    name = newName;
}
//sets the employee address to given address
void Employee::setAddress(std::string newAddress){
    address = newAddress;
}

//GETTERS
//returns Employee name
std::string Employee::getName(){
    return name;
}
//returns Employee address
std::string Employee::getAddress(){
    return address;
}

//not working?
//input validation
//template<typename T>bool Employee::numberIsValid(T num){return (num >= 0);}
