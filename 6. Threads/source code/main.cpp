/***************************************************************************************

Title: Assignment 6 - Multi-threaded Programming
Author: Alex Paquette
Date: 12/02/2021

Description:    This program opens a file for writing and sends it to the SecuritySystem
                class. It then creates five threads of the monitor() function from
                SecuritySystem and runs until the user presses  Enter.

***************************************************************************************/

#include "SecuritySystem.h"
#include<fstream>
#include<thread>

using namespace std;

//True: 1
//False: 0

int main(){
    const std::string FILENAME = "logFile.txt";
    ofstream fs(FILENAME);
    if(fs.is_open()){//if the file is opened successfully
        SecuritySystem::setFileStream(fs);//set filestream for the Security System

        //five threads
        thread frontDoor(SecuritySystem::monitor, "Front Door");
        thread refrigerator(SecuritySystem::monitor, "Refrigerator");
        thread wineCellar(SecuritySystem::monitor, "Win Cellar");
        thread catRoom(SecuritySystem::monitor, "Cat Room");
        thread gameRoom(SecuritySystem::monitor, "Game Room");

        //enter to shutdown
        cout << "Press enter to turn off the system: \n";
        system("pause");

        SecuritySystem::toggleShutDown();//sets shutdown to true

        //wait for  these threads to finish before continuing
        frontDoor.join();
        refrigerator.join();
        wineCellar.join();
        catRoom.join();
        gameRoom.join();

        fs.close();//close the file stream
    }else{//output message if file doesn't open
        cout << "\aProblem opening file";
    }

    return 0;
}
