/***************************************************************************************

Title: Assignment 3 - Inventory Items Declarations
Author: Alex Paquette
Date: 11/02/2021

Description:    This file defines the Inventory Item class to be used
                in the Inventory System. It includes insertion and 
                extraction operators for the terminal and, and insertion operator for
                file IO as well as fields for product number, name, stock quantity,
                and the price. 
                
                There is a boolean function that validates number inputes
                and ensures the values is zero or greater. The function
                is abstracted with a typename T variable as to accept any
                type of number variables (int, float, etc.)

                The constructor has default values for each field and uses 
                the setter functions to allocate the values to the instances.

                There are setter function for each field, and the number setters
                use the previously defined validation function to ensure the 
                values are zero or greater. Any invalid value detected sets 
                the actual value to zero

                There are getter functions for each field that returns the 
                value of those fields

***************************************************************************************/

#ifndef INVENTORYITEMS_H
#define INVENTORYITEMS_H
#include<fstream>

class InventoryItems{
    //insertion and extraction operators
    friend std::ostream& operator<<(std::ostream&, InventoryItems&);
    friend std::ofstream& operator<<(std::ofstream&, InventoryItems&);
    friend std::istream& operator>>(std::istream&, InventoryItems&);
  private:
    //class fields
    int productNumber;
    char name[50];
    int stockQuantity;
    float price;

    //input validation
    template<typename T>bool numberIsValid(T num);
  public:
    InventoryItems(int newProductNumber = 0, char newName[50] = new char[50], int newStockQuantity = 0, float newPrice = 0);
    //setters
    int setProductNumber(int);
    char* setName(char[50]);
    int setStockQuantity(int);
    float setPrice(float);

    //getters
    int getProductNumber();
    char* getName();
    int getStockQuantity();
    float getPrice();
};

#endif // INVENTORYITEMS_H
