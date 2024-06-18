#include "InputManagement.h"
#include <limits>

/*used if cin fails
* will take a reference to istream and ignore all inputs
* and invalid input is sent to the terminal*/
void invalidInput(std::istream& in) {
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\a\n!!!Invalid Input!!!\n\n";
}
