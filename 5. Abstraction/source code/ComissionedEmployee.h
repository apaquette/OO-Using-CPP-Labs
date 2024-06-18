/***************************************************************************************

Title: Assignment 5 - Abstraction
Author: Alex Paquette
Date: 11/28/2021

Description:    This file declares the Comissioned Employee child class and includes attributes
                and functions unique to it

***************************************************************************************/
#ifndef COMISSIONEDEMPLOYEE_H_INCLUDED
#define COMISSIONEDEMPLOYEE_H_INCLUDED
#include "Employee.h"

class ComissionedEmployee : public Employee{
    private:
        double sales;
        double commRate;
    public:
        ComissionedEmployee(std::string name = "NEW EMPLOYEE", std::string address = "", double sales = 0.0, double commRate = 0.0);

        //setters
        void setSales(double newSalary);
        void setCommRate(double newWeeks);

        //getters
        double getSales();
        double getCommRate();

        //input validation
        template<typename T>bool numberIsValid(T num);

        //misc
        double pay();
};

#endif // COMISSIONEDEMPLOYEE_H_INCLUDED
