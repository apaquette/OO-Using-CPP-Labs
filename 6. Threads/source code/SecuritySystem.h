/***************************************************************************************

Title: Assignment 6 - Multi-threaded Programming
Author: Alex Paquette
Date: 12/02/2021

Description:    Static class for Security system. Contains static functions and variables

***************************************************************************************/

#ifndef SECURITYSYSTEM_H_INCLUDED
#define SECURITYSYSTEM_H_INCLUDED
#include<iostream>
#include<fstream>

class SecuritySystem{
    private:
        static bool shutDown;//true = system is off false = system is on
        static std::ofstream* fileStream;//pointer to filestream created in main() function
        static std::string timeString();
        static void log(std::string, std::string);
    public:
        //setter
        static void toggleShutDown();//sets on/off
        static void setFileStream(std::ofstream&);
        //getter
        static bool getShutDown();
        //other
        static void monitor(std::string);
};


#endif // SECURITYSYSTEM_H_INCLUDED
