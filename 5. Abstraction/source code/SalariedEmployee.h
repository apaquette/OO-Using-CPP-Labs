/***************************************************************************************

Title: Assignment 5 - Abstraction
Author: Alex Paquette
Date: 11/28/2021

Description:    This file declares the Salaried Employee child class and includes attributes
                and functions unique to it

***************************************************************************************/

#ifndef SALARIEDEMPLOYEE_H_INCLUDED
#define SALARIEDEMPLOYEE_H_INCLUDED
#include "Employee.h"

class SalariedEmployee : public Employee{
    private:
        double salary;
        int weeks;
    public:
        SalariedEmployee(std::string name = "NEW EMPLOYEE", std::string address = "", double salary = 0.0, int weeks = 0);

        //setters
        void setSalary(double newSalary);
        void setWeeks(int newWeeks);

        //getters
        double getSalary();
        int getWeeks();

        //input validation
        template<typename T>bool numberIsValid(T num);

        //misc
        double pay();
};

#endif // SALARIEDEMPLOYEE_H_INCLUDED
