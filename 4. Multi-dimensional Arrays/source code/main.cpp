/***************************************************************************************

Title: Assignment 4 - Multi-Dimensional Arrays
Author: Alex Paquette
Date: 11/23/2021

Description:    This program displays a menu that allows the user to select 6
                options:
                1 - Show one result of one team
                2 - Show all results of one team
                3 - Show all results for one run
                4 - The average of one run
                5 - Sum of all runs for a team
                6 - Exit the program
                options  1 through 5 have sub menus to select which team or run the
                user wants to select. The sub menus also allow the user to return to
                the Main Menu

***************************************************************************************/

#include <iostream>
#include "InputManagement.h"

using namespace std;

//global constants
const int QUIT = 6, TEAMNUM = 10, RUNNUM = 4;

//Formats menu
string getMenu(string menuContent){
    string menu = "";
    menu += "\n\t----------------------------\n";
    menu += menuContent;
    menu += "\t----------------------------\n";

    return menu;
}

//generates sub menu for teams selection
string getTeamsMenu(string *a){
    string message = "\n\tPick a Team:\n";
    for(int i = 0; i <= TEAMNUM; i++){
        message += "\n\t";
        message += to_string(i+1);
        message += ". ";
        if(i == TEAMNUM){
            message += "Return to Main Menu";
        }else{
            message += a[i];
        }
    }
    message += "\n\n";
    return message;
}

//displays a specified run for a specified team
void showTeamRun(string team, float run, int runSelection){
    cout << "\n\t" << team << " Run " << runSelection + 1 << ": " << run;
}

//displays all the results for all teams for one race
//takes runs array, and the race selected
void showRaceRuns(float runs[][RUNNUM], int runSelection){
    cout << "\n\tRun " << runSelection + 1 << ":";
    for (int i = 0; i < RUNNUM; i++){
        cout << " " << *(*(runs+i)+runSelection);
        if(i != RUNNUM-1){
            cout << ",";
        }
    }
}

//displays the average of all races for a run
void showRaceAverage(float runs[][RUNNUM], int runSelection){
    float average = 0;
    cout << "\n\tRun " << runSelection + 1 << ": ";
    for (int i = 0; i < TEAMNUM; i++){
        average += runs[i][runSelection];
    }
    cout << (average/TEAMNUM);
}


int main(){
    int input, teamSelection, runSelection;
    float total = 0;

    //data
    string teams[TEAMNUM] = {"Germany", "Germany", "South Korea", "Switzerland", "Latvia", "Canada", "Austria", "Germany", "United States", "Latvia"};
    float runs[TEAMNUM][RUNNUM] = {
                                {48.54, 49.01, 48.76, 49.54},
                                {48.74, 49.16, 48.90, 49.58},
                                {48.65, 49.19, 48.89, 49.65},
                                {49.05, 49.16, 48.87, 49.51},
                                {48.82, 49.39, 48.91, 49.53},
                                {48.85, 49.28, 48.95, 49.61},
                                {49.10, 49.21, 49.03, 49.56},
                                {48.95, 49.26, 49.10, 49.80},
                                {49.09, 49.26, 49.08, 49.77},
                                {49.18, 49.26, 49.34, 49.63}
                            };

    //menus
    string mainMenu = getMenu("\n\tMain Menu\n\n\t1. Team One Result\n\t2. Team All Results\n\t3. Race Result\n\t4. Average Race Result\n\t5. Team Series Total\n\t6. Exit\n\n");
    string teamsMenu = getMenu(getTeamsMenu(teams));
    string runsMenu = getMenu("\n\tPick a run:\n\n\t1. Run 1\n\t2. Run 2\n\t3. Run 3\n\t4. Run 4\n\t5. Return to Main Menu\n\n");

    do{
        input = QUIT + 1;
        teamSelection = -1;
        runSelection = -1;
        input = getInput(1, QUIT, mainMenu);
        switch(input){
            case 1://One result for a team
                teamSelection = getInput(1, TEAMNUM+1, teamsMenu) - 1;
                if(teamSelection != TEAMNUM){//allows user to go back to menu
                    runSelection = getInput(1, RUNNUM+1, runsMenu) - 1;
                    if(runSelection != RUNNUM){//allows user to go back to menu
                        showTeamRun(*(teams+teamSelection), *(*(runs+teamSelection)+runSelection), runSelection);
                    }
                }
                break;
            case 2://All results for a team
                teamSelection = getInput(1, TEAMNUM+1, teamsMenu) - 1;
                if(teamSelection != TEAMNUM){//allows user to go back to menu
                    cout << "\n\t" << teams[teamSelection] << ":";
                    for (float f : runs[teamSelection]){//displays each run for a specific team
                        cout << " " << f;
                        if(f != runs[teamSelection][RUNNUM-1]){
                            cout << ",";
                        }
                    }
                }
                break;
            case 3://All results for one race
                runSelection = getInput(1, RUNNUM+1, runsMenu) - 1;
                if(runSelection != RUNNUM){//allows user to go back to menu
                    showRaceRuns(runs, runSelection);
                }
                break;
            case 4://Average for one race
                runSelection = getInput(1, RUNNUM+1, runsMenu) - 1;
                if(runSelection != RUNNUM){//allows user to go back to menu
                    showRaceAverage(runs, runSelection);
                }
                break;
            case 5://Total for any team across the entire series
                teamSelection = getInput(1, TEAMNUM+1, teamsMenu) - 1;
                if(teamSelection != TEAMNUM){//allows user to go back to menu
                   total = 0;
                    cout << "\n\t" << teams[teamSelection] << " Total: ";
                    for (float f: runs[teamSelection]){//adds up the runs for a specific team
                        total += f;
                    }
                    cout << total;
                }
                break;
        }
    }while(input != QUIT);
    return 0;
}
