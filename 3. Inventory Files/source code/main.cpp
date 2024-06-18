/****************************************************************************************

Title: Assignment 3 - Main Menu
Author:         Alex Paquette
Date:           11/02/2021

Description:    This file includes the main menu for the Inventory System
                and allows the user to navigate between different options
                with a number input (1 through 4). Any value outside those
                bounds or other invalid input is discarted and the user is
                informed of the invalid input.

***************************************************************************************/
#include "InventorySystem.h"
#include "InputManagement.h"

int main() {
  int select = -1;
  const std::string FILENAME = "Inventory.dat";

    do{
        select = -1;
        std::cout << "1 - Initialize File\n2 - Enter Data\n3 - View Data\n4 - Exit\n\nEnter: ";
        std::cin >> select;

        system("cls");
        switch(select){
            case 1:
                if (permissionProvided()) {
                    initializeFile(FILENAME);
                }
                break;
            case 2:
                enterData(FILENAME);
                break;
            case 3:
                displayData(FILENAME);
                break;
            case 4://Exit Program
                break;
            default:
                invalidInput(std::cin);
                break;
        }
    }while(select != 4);

    return 0;
}
