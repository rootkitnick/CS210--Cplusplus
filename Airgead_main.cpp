#include <iostream>
#include "Data_Input.h"


using namespace std;

/**********************************************************************************
 *This program is designed to teach students fiscal responsibility by showing the 
 *year end balances and year end earned interest on savings accounts with monthly 
 *deposits and without monthly deposits.
 *
 *Author: Nicholas Phelps
 *Date: October 2, 2021
 **********************************************************************************/

int main() {
	DataInput userInput;                //Initialize userInput
	char userChar;                      //User character used to determine program termination

	//Initial block to display data input menu, prompt user for input, 
	//display data input menu with user values, and finally display year end balances
	//with and without monthly deposits
	userInput.PrintDataInput();
	userInput.PrintUserInput();
	userInput.DisplayNoMonthly();
	cout << endl;
	userInput.DisplayWithMonthly();

	//Determine whether the user would like to continue
	cout << "Would you like to enter new values? ('y' or 'n')" << endl;
	cin >> userChar;
	
	//Enter a loop that continues to get user values and display year end 
	//balances until user enters 'n' to quit
	while (userChar != 'n') {
		userInput.PromptUser();
		userInput.DisplayNoMonthly();
		cout << endl;
		userInput.DisplayWithMonthly();
		cout << "Would you like to enter new values? ('y' or 'n')" << endl;
		cin >> userChar;
	}
	


	return 0;
}