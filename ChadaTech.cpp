#include <iostream>
#include <Clock.h>

using namespace std;

/******************************************************************************
* This program is designed to display two clocks, one in standard 12-hour time
* and one in international 24-hour time. It allows the user to use simple input
* commands to adjust the clocks hours, minutes, and seconds simultaneously and
* updates the AM or PM on the 12-hour clock based on the current input.
* 
* Author: Nicholas Phelps
* Date: September 16, 2021
* Updated: September 17, 2021
******************************************************************************/

//This function displays a menu with all user options 
void printMenu() {

	cout << "                   " << "**************************" << endl;
	cout << "                   " << "* 1 - Add One Hour       *" << endl;
	cout << "                   " << "* 2 - Add One Minute     *" << endl;
	cout << "                   " << "* 3 - Add One Second     *" << endl;
	cout << "                   " << "* 4 - Exit Program       *" << endl;
	cout << "                   " << "**************************" << endl;
	cout << " " << endl;
	cout << "                   " << "Please enter menu selection: " << endl;

}

int main() {

	//Declare all  variables that will be needed in the main function
	StandardClock standardClock(0, 0, 0);
	InternationalClock internationalClock(0, 0, 0);
	string userInput;

	//Create a do while loop that will display both clocks and the menu as long as user input is not 4
	do {

		displayClocks(standardClock, internationalClock);  //Calls the display clock function
		printMenu();                                       //Calls the print menu function
		cin >> userInput;                                  //Receives user input for the menu

		if (userInput == "1") {                            //Adds one hour to both clocks if user input is 1
			standardClock.addOneHour();
			internationalClock.addOneHour();
		}
		else if (userInput == "2") {                       //Adds one minute to both clocks if user input is 2
			standardClock.addOneMinute();
			internationalClock.addOneMinute();
		}
		else if (userInput == "3") {                        //Adds one second to both clocks if user input is 3
			standardClock.addOneSecond();
			internationalClock.addOneSecond();
		}
		else if (userInput == "4") {                         //Exits the program if user input is 4
			cout << "Exiting program..." << endl;
		}
		else {                                               //Prompts user for valid entry if not 1 - 4
			cout << "Invalid entry. Please try again." << endl;
		}

		for (int i = 0; i < 40; ++i) {                       //Clears the menu by printing 40 new lines. This code was sourced from 
			cout << endl;                                    //Professor Gregori on the announcments page on September 15, 2021.
		}
	} while (!userInput._Equal("4"));                        //Ends the do while loop when user enters "4"


	return 0;
}
