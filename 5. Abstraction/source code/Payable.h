/***************************************************************************************

Title: Assignment 5 - Abstraction
Author: Alex Paquette
Date: 11/28/2021

Description:    This file declares the interface for Payable  to be used for the employee
                classes.

***************************************************************************************/

#ifndef PAYABLE_H_INCLUDED
#define PAYABLE_H_INCLUDED

class Payable{
    public:
        virtual double pay() = 0;
};

#endif // PAYABLE_H_INCLUDED
