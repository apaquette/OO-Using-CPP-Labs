/******************************************************************************************

Title: Assignment 3 - Inventory System Definitions
Author: Alex Paquette
Date: 11/02/2021

Future Improvements:       
            Possible issue with minimum product number. Currently works
            fine because inventory items will not accept anything less than zero
            however, if someone were to change MIN_PNUM to below zero, these records
            would conflict with the restriction for products numbers from InvenotryItems.h

********************************************************************************************/
#include <fstream>
#include "InventorySystem.h"
#include "InventoryItems.h"
#include "InputManagement.h"

//constants
const int MAX_PNUM = 100;//max product number
const int MIN_PNUM = 1;//min product number

/*Validates that the user wantas to create a new blank binary file that will
* overwrite previously existing data
* Will take a 1 to proceed, and 2 to abort. Any other input is discarted or ignored
* and user is informed of invalid input
* Will return true if user selects 1, or false if user selects 2
* Loop ends if either 1 or 2 are selected*/
bool permissionProvided() {
    int select = 0;

    system("cls");

    do {
        select = 0;
        std::cout << "\aWARNING\nThis will delete all previous data. Proceed?\n1 - Yes\n2 - No\nEnter: ";
        std::cin >> select;

        system("cls");

        if (select != 1 && select != 2) {
            invalidInput(std::cin);
        }
    } while (select != 1 && select != 2);

    if (select == 1)
        return true;
    else
        return false;
}

/*Checks if a given integer is between the min and max allowed values
* for a product number. These min and max values are defined by the
* MIN_PNUM and MAX_PNUM constants
* returns true if valid, returns false if invalid and outputs a warning*/
bool productNumberIsGood(int pNum) {
    if (pNum >= MIN_PNUM && pNum <= MAX_PNUM) {
        return true;
    }
    else {
        std::cout << "\a\nProduct Number must be between "<< MIN_PNUM << " and " << MAX_PNUM << std::endl;
        system("pause");
        return false;
    }
}

/*Will create the max number of records in a file based on the MAX_PNUM constant
* a file is created for binary writing and is named based on the FILENAME variable
* checks if the file opens, then writes blank records to the file*/
void initializeFile(const std::string FILENAME) {
    const int MAX_RECORDS = MAX_PNUM - 1;
    std::fstream itemFile(FILENAME, std::ios::binary | std::ios::out);

    if (itemFile.good()) {
        for (int x = 0; x < MAX_RECORDS; x++) {
            itemFile.write(reinterpret_cast <char*>(new InventoryItems), sizeof(InventoryItems));
        }
    }
    else {
        system("cls");
        std::cout << "\a\nProblem opening file.\n\n";
    }

    itemFile.close();
}

/*Allows the user to enter any number of items into the binary file
* Checks if the file opened properly, and allows the user to enter
* an unlimited number of files until they enter 2

Future improvements:    The user should be informed if an item with a given product number
                        already exists and whether or not they want to overwrite it*/
void enterData(const std::string FILENAME) {
    std::fstream itemFile(FILENAME, std::ios::binary | std::ios::in | std::ios::out);
    
    if (itemFile.good()) {
        InventoryItems item;
        int select = -1;

        do{
            select = -1;
            std::cout << "Enter a record?\n1 - Yes\n2 - No\n\nEnter: ";
            std::cin >> select;

            system("cls");

            if (select != 1 && select != 2) {
                invalidInput(std::cin);
            }else if(select == 1){
                std::cin >> item;

                system("cls");

                if (productNumberIsGood(item.getProductNumber())) {
                    itemFile.seekp(((double)item.getProductNumber() - 1) * sizeof(InventoryItems));
                    itemFile.write(reinterpret_cast<char*>(&item), sizeof(InventoryItems));
                }
            }
        } while (select != 2);

        itemFile.close();
    }else{
        system("cls");
        std::cout << "\a\nProblem opening file.\n\n";
    }
}

/*Thi function will take a product number from the user and display the contents of that Inventory item
The user will be informed if no product exists for a product number*/
void displayData(const std::string FILENAME) {
    int select = -1;

    do {
        select = -1;
        std::cout << "Enter a product number to view. Enter zero (0) to exit.\nEnter: ";
        std::cin >> select;

        system("cls");

        if (std::cin.fail()) {
            invalidInput(std::cin);
        }else if (select == 0) {
            break;//exit program if zero is selected.
        }else if (productNumberIsGood(select)) {
            std::fstream itemFile(FILENAME, std::ios::binary | std::ios::in);
            
            if (itemFile.good()) {
                InventoryItems item;

                itemFile.seekg(((double)select - 1) * sizeof(InventoryItems));
                itemFile.read(reinterpret_cast<char*>(&item), sizeof(InventoryItems));

                if (item.getProductNumber() == 0) {
                    std::cout << "No item with this product number exists.\n";
                }else {
                    std::cout << item << std::endl;
                }
            }else {
                system("cls");
                std::cout << "\a\nProblem opening file.\n\n";
            }
            itemFile.close();
        }
    } while (select != 0);
}