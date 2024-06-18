#include "SecuritySystem.h"
#include<stdio.h>
#include<time.h>
#include<cstdlib>
#include<thread>
#include<chrono>
#include<mutex>
#include<string>

//instantiate static variables
bool SecuritySystem::shutDown = false;
std::ofstream* SecuritySystem::fileStream = nullptr;

//passes a reference to a file
void SecuritySystem::setFileStream(std::ofstream& newFileStream) {
    fileStream = &newFileStream;
}

//credit: Jim
std::string SecuritySystem::timeString(){
    const int BUFFER = 20;
    char timeDate[BUFFER];
    time_t rawtime = time(0);
    struct tm timeinfo;
    localtime_s(&timeinfo, &rawtime);

    strftime(timeDate, BUFFER, "%Y-%m-%d %I:%M:%S", &timeinfo);

    return timeDate;
}

//toggles shutdown of the system
//if on, turn off
//if off, turn on
void SecuritySystem::toggleShutDown(){
    if(shutDown){
        shutDown = false;
    }else{
        shutDown = true;
    }
}

//returns current status of the system (true/false)
bool SecuritySystem::getShutDown(){
    return shutDown;
}

//monitor item specified passed as a string
//generates random number put to sleep for random amount of tiem
void SecuritySystem::monitor(std::string name){
    log(name, "starting up");
    srand(time(0));
    do{//while the system is not shut down, log simulated even
        log(name, "Simulated Event");
        std::this_thread::sleep_for(std::chrono::milliseconds(rand()%2000));
    }while(!shutDown);

    log(name, "Shutting Down");//log the system is shutting down
}

std::mutex counter_mutex;//create mutex c ounter
void SecuritySystem::log(std::string name, std::string message){
    std::lock_guard<std::mutex>myLock(counter_mutex);//guard code to prevent collision
    *fileStream << timeString() << "\t" << message << "\t" << name << "\n";//write log to the text file containing timestamp, name, and message with tab delimeter
}
