/****************************************************

Title: Assignment 3 - Inventory Items Definitions
Author: Alex Paquette
Date: 11/02/2021

******************************************************/

#include <string>
#include <math.h>
#include <limits>
#include "InventoryItems.h"
#include "InputManagement.h"


/*CONSTRUCTOR*/
/*InventoryItem constructor to set the Product Number, Name, Stock Quanityt, and Price*/
InventoryItems::InventoryItems(int newProductNumber, char newName[50], int newStockQuantity, float newPrice) {
  setProductNumber(newProductNumber);
  setName(newName);
  setStockQuantity(newStockQuantity);
  setPrice(newPrice);
}

/*SETTERS*/
/*This function will set the product number to a given integer
* It will check the integer to ensure it is a valid integer
* If it is valid, the product number will be set as the given number
* If it is invalid, the product number will be set to zero
* Returns the resulting product number*/
int InventoryItems::setProductNumber(int newProductNumber){
    if(numberIsValid<int>(newProductNumber)){
        productNumber = newProductNumber;
    }else{
        productNumber = 0;
    }
    return productNumber;
}

/*This function will set the name to a given character array and return the resulting name*/
char* InventoryItems::setName(char newName[50]) {
    for (int x = 0; x < 50; x++) {
        name[x] = newName[x];
    }
    return name;
}

/*This function will set the stock quantity to a given integer
* It will check the integer to ensure it is a valid integer
* If it is valid, the stock quantity will be set as the given number
* If it is invalid, the stock quantity will be set to zero
* Returns the resulting stock quantity*/
int InventoryItems::setStockQuantity(int newStockQuantity){
    if(numberIsValid<int>(newStockQuantity)){
        stockQuantity = newStockQuantity;
    }else{
        stockQuantity = 0;
    }
    return stockQuantity;
}

/*This function will set the product price to a given float
* It will check the integer to ensure it is a valid integer
* If it is valid, the product price will be set as the given number to two decimal places
* If it is invalid, the product price will be set to zero
* Returns the resulting product price*/
float InventoryItems::setPrice(float newPrice){
    if(numberIsValid<float>(newPrice)){
        price = floorf(newPrice * 100) / 100;
    }else{
        price = 0.0;
    }
    return price;
}

/*GETTERS*/
/*This function will return the product number*/
int InventoryItems::getProductNumber(){return productNumber;}

/*This function will return the product name*/
char* InventoryItems::getName() {return name;}

/*This function will return the stock quantity*/
int InventoryItems::getStockQuantity(){return stockQuantity;}

/*This function will return the product price*/
float InventoryItems::getPrice(){return price;}

/*VALIDATION*/
/*This function will check that a given number is greater than or equal to zero*/
template<typename T>bool InventoryItems::numberIsValid(T num){return (num >= 0);}

/*IO OPERATORS*/
/*Overloaded insertion operator to ouput an InventoryItem to the terminal
* Will display each field with text in front of it identifying it*/
std::ostream& operator<<(std::ostream& out, InventoryItems& item){
    out << "Product Number: " << item.getProductNumber() << "\tName: " << item.getName() << "\tStock: " << item.getStockQuantity() << "\tPrice: $" << item.getPrice();
    return out;
}

/*Overloaded insertion operator to ouput an InventoryItem to a file
* Will insert a space between each field for future extraction*/
std::ofstream& operator<<(std::ofstream& out, InventoryItems& item){
    out << item.getProductNumber() << " " << item.getName() << " " << item.getStockQuantity() << " " << item.getPrice();
    return out;
}

/*Overloaded extraction operator to enter values to an InventoryItem
* Will take input from the user for each field
* Setter functions are used to ensure inputs are valid
* For each input (except string), use is forced to enter a valid number
* user is informed if input is invalid*/
std::istream& operator>>(std::istream& in, InventoryItems& item) {
    int newProductNumber, newStockQuantity;
    char newName[50];
    float newPrice;

    do {
        if (in.fail()) {
            invalidInput(in);
        }
        std::cout << "Enter the product number: ";
        in >> newProductNumber;
        system("cls");
    } while (in.fail());

    std::cout << "Enter the product name: ";
    in.ignore();
    in.getline(newName, 50);
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("cls");

    do {
        if (in.fail()) {
            invalidInput(in);
        }
        std::cout << "Enter the stock quantity: ";
        in >> newStockQuantity;
        system("cls");
    } while (in.fail());

    do {
        if (in.fail()) {
            invalidInput(in);
        }
        std::cout << "Enter the product price: ";
        in >> newPrice;
        system("cls");
    } while (in.fail());

    item.setProductNumber(newProductNumber);
    item.setName(newName);
    item.setStockQuantity(newStockQuantity);
    item.setPrice(newPrice);

    return in;
}
