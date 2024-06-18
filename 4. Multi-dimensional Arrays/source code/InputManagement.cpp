#include "InputManagement.h"
#include <limits>

/*used if cin fails
* will take a reference to istream and ignore all inputs
* and invalid input is sent to the terminal*/
void invalidInput(std::istream& in) {
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\a\n\t!!!Invalid Input!!!\n\n";
}

int getInput(int low, int high, std:: string message){
    int choice;
    do{
        choice = low - 1;
        std::cout << message << std::endl;
        std::cout << "\n\tEnter between ";
        std::cout << low;
        std::cout << " and ";
        std::cout << high;
        std::cout << " >> ";
        std::cin >> choice;
        system("cls");
        if(choice < low || choice > high){
            invalidInput(std::cin);
        }
    }while(choice < low || choice > high);
    system("cls");
    return choice;
}
