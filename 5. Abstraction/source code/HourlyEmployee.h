/***************************************************************************************

Title: Assignment 5 - Abstraction
Author: Alex Paquette
Date: 11/28/2021

Description:    This file declares the Hourly Employee child class and includes attributes
                and functions unique to it

***************************************************************************************/
#ifndef HOURLYEMPLOYEE_H_INCLUDED
#define HOURLYEMPLOYEE_H_INCLUDED
#include "Employee.h"

class HourlyEmployee : public Employee{
    private:
        double hours;
        double hourlyRate;
    public:
        HourlyEmployee(std::string name = "NEW EMPLOYEE", std::string address = "", double hours = 0.0, double hourlyRate = 0.0);

        //setters
        void setHours(double newHours);
        void setHourlyRate(double newHourlyRate);

        //getters
        double getHours();
        double getHourlyRate();

        //input validation
        template<typename T>bool numberIsValid(T num);

        //misc
        double pay();
};

#endif // HOURLYEMPLOYEE_H_INCLUDED
