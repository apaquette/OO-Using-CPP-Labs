/***************************************************************************************

Title: Assignment 4 - Multi-Dimensional Arrays
Author: Alex Paquette
Date: 11/23/2021

Description:    This file defines the invalidInput() and getInput functions used to handle
				improper input from the user. Any future input management functions
				can be added to this file.

***************************************************************************************/
#ifndef INPUTMANAGEMENT_H
#define INPUTMANAGEMENT_H
#include<iostream>

void invalidInput(std::istream&);
int getInput(int low, int high, std::string message = "");

#endif
