/***************************************************************************************

Title: Assignment 5 - Abstraction
Author: Alex Paquette
Date: 11/28/2021

Description:    This file declares the parent employee classes and the basic variables
                and functions the child classes will have

***************************************************************************************/
#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include<iostream>
#include "Payable.h"

class Employee : public Payable{
    private:
        std::string name;
        std::string address;
    public:
        Employee(std:: string name = "NEW EMPLOYEE", std::string address = "");

        //setters
        void setName(std::string newName);
        void setAddress(std::string newAddress);

        //getters
        std::string getName();
        std::string getAddress();

        //virtual double pay() = 0;

        //not working?
        //input validation
        //template<typename T>bool numberIsValid(T num);
};

#endif // EMPLOYEE_H_INCLUDED
