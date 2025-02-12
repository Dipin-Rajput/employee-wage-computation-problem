# include <iostream>
# include <cstdlib>
# include <ctime>
using namespace std;

// UC-1: Check Attendance

int checkAttendance(){
    
    int attendance = rand() % 2; // rand() function to generate random number between 0 and 1

    if(attendance == 1){
        cout << "\nEmployee is Present";
    }
    else{
        cout << "\nEmployee is Absent";
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

// UC-5: Check Monthly Wages

int checkMonthlyWages(){

    int workingDayPerMonth = 20, wagesPerHour = 20, fullDayHours = 8, partTimeHours = 8;
    int totalWages = 0;

    for(int i = 1; i <= workingDayPerMonth; i++){ // Loop to calculate wages for 20 days

        int fullDayStatus = checkAttendance();
        int fullDayWages = 0;

        if(fullDayStatus == 1){

            fullDayWages = wagesPerHour * fullDayHours; // Calculate full day wages for particular day
            totalWages += fullDayWages; // Add wages to total wage

            cout << "\nYour Day " << i << " full day wages are: " << fullDayWages;
        }
        else{
            cout << "\nYour Day " << i << " full day wages are: " << fullDayWages;
        }

        int partTimeStatus = checkAttendance();
        int partTimeWages = 0;

        if(partTimeStatus == 1){

            partTimeWages = wagesPerHour * partTimeHours; // Calculate part-time wages for particular day
            totalWages += partTimeWages; // Add wages to total wage

            cout << "\nYour Day " << i << " part-time wages are: " << partTimeWages;
        }
        else{
            cout << "\nYour Day " << i << " part-time wages are: " << partTimeWages;
        }

        cout << "\n";
    }

    return totalWages;
}

int main(){

    // srand(seed): function to generate different random number each time.
    // seed: is an integer used to intialize the random number generator.
    // time(0): returns the current time in seconds.

    srand(time(0));

    cout << "\n-------------------- Welcome to Employee Wage Computation Program --------------------\n";

    cout << "\nEnter 0 to exit";
    cout << "\nEnter 1 to check attendance";
    cout << "\nEnter 2 to check daily wage";
    cout << "\nEnter 3 to check part-time wage";
    cout << "\nEnter 4 to check monthly wages\n";

    int choice, fullDayWage, partTimeWage, totalWage;

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

        case 4:
            totalWage = checkMonthlyWages(); // function call to check monthly wages
            cout << "\nYour total wages are: " << totalWage;
            break;

        default:
            cout << "\nInvalid Choice!, Please enter from above choices.";
            break;
    }

    return 0;
}