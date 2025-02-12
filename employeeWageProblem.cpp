# include <iostream>
# include <cstdlib>
# include <ctime>
using namespace std;

// UC-1: Check Attendance

int checkAttendance(){

    // srand(seed): function to generate different random number each time.
    // seed: is an integer used to intialize the random number generator.
    // time(0): returns the current time in seconds.

    srand(time(0));
    
    int attendance = rand() % 2; // rand() function to generate random number between 0 and 1

    if(attendance == 1){
        cout << "\nEmployee is Present\n";
    }
    else{
        cout << "\nEmployee is Absent\n";
    }
    
    return attendance;
}

// UC-2: Check Daily Wage

int checkDailyWage(){

    int status = checkAttendance(); // Call check attendance function
    int wagesPerHour = 20;
    int fullDayHours = 8;
    int wages = 0;

    if(status == 1){
        wages = wagesPerHour * fullDayHours; // Calculating daily wage
        return wages;
    }
    else{
        return 0;
    }
}

// UC-3: Check Part-Time Wage

int checkPartTimeWage(){

    int status = checkAttendance(); // Call check attendance function
    int wagesPerHour = 20;
    int partTimeHours = 8;
    int wages = 0;

    if(status == 1){
        wages = wagesPerHour * partTimeHours; // Calculating part-time wage
        return wages;
    }
    else{
        return 0;
    }
}

int main(){

    cout << "\n-------------------- Welcome to Employee Wage Computation Program --------------------\n";

    cout << "\nEnter 0 to exit";
    cout << "\nEnter 1 to check attendance";
    cout << "\nEnter 2 to check daily wage";
    cout << "\nEnter 3 to check part-time wage\n";

    int choice, fullDayWage, partTimeWage;

    cout << "\nEnter your choice: ";
    cin >> choice;

    // UC4: Switch - Case Implementation

    switch(choice){

        case 0:
            cout << "\nExiting the Program, Thank You for Joining.";
            break;

        case 1: 
            checkAttendance(); // function call to check whether employee is present or absent
            break;

        case 2: 
            fullDayWage = checkDailyWage(); // function call to check full day wage
            cout << "\nYour daily wage is: " << fullDayWage << "\n";
            break;

        case 3:
            partTimeWage = checkPartTimeWage(); // function call to check part-time wage
            cout << "\nYour part-time wage is: " << partTimeWage << "\n";
            break;

        default:
            cout << "\nInvalid Choice!, Please enter form above choices.";
            break;
    }

    return 0;
}