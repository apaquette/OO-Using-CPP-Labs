/***************************************************************************************

Title: Assignment 5 - Abstraction
Author: Alex Paquette
Date: 11/28/2021

Description:    This program creates an instance of each concrete class and adds them
                into an Employee array. Then it iterates through each item in the array
                calling the pay() function to show the individual functions are unique
                for each class type

***************************************************************************************/

#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "ComissionedEmployee.h"

using namespace std;

int main(){
    //Instances of Concrete classes
    HourlyEmployee hEmp("Alex - Hourly", "33 Dubeau", 38, 18.75);
    SalariedEmployee sEmp("Alex - Salaried", "33 Dubeau", 80000.00, 20);
    ComissionedEmployee cEmp("Alex - Comissioned", "33 Dubeau", 100000, 0.03);

    //add instances to a single array
    Employee* eArr[] = {&hEmp, &sEmp, &cEmp};

    //iterate through the array and call pay() function to show correct function is used
    for(Employee* e : eArr){
        cout << e->getName() << " Pay: " << e->pay() << endl;
    }
    cin.get();
    return 0;
}
