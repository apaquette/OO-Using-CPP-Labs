/***************************************************************************************

Title: Assignment 3 - Inventory System Declarations
Author: Alex Paquette
Date: 11/02/2021

Description:	This file defines the Inventory System functions
				used in the main menu.

				Miscelaneous functions include the handling of invalid inputs,
				permissions validation for the inilization of a new blank binary file,
				and validation of whether a product number is within the acceptable
				range (currently 1 to 100)

				Menu functions include the inilization of a binary file, inserting data
				into the binary file, and displaying data from the binary file

***************************************************************************************/

#ifndef INVENTORYSYSTEM_H
#define INVENTORYSYSTEM_H
#include<iostream>

//misc
bool permissionProvided();
bool productNumberIsGood(int);

//menu functions
void initializeFile(const std::string filename);
void enterData(const std::string filename);
void displayData(const std::string filename);
#endif // INVENTORYSYSTEM_H