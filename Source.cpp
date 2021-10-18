#include <Python.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;

/*
This program is designed to accomplish four main things. 
	One: To display a menu to the user with all available program options, validate user input, and pass input between 
	     C++ and python files.
	Two: To take an input file, iterate over the strings in that file, and display a list of all items and the number
	      of times those items appeared in the input file. 
	Three: To open an input file, receive user string and look for that string in the input file, then display how many
	        times that item occurred.
	Four: To take an input file, iterate over each string, and replace the frequency of an item with a text-based  
	       histogram. 
	
	Author: Nicholas Phelps
	Date: October 15, 2021
*/

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

/*
Description: 
	This function passes a user string to a python function, returns the frequency of that item in an input file, and 
	displays that information to the user.
Example:
	Onions occurred 4 times.
Return:
	None*/
void callItemFreq() {
	string userString;                     //Declare variable for user item
	int itemFreq = 0;                      //Declare variable for item frequency

	cout << "Please enter the item you are looking for: " << endl;
	cin >> userString;                     //Prompt user for item name

	itemFreq = callIntFunc("PrintMe", userString);   //Get item frequency by calling python function

	//Print user item and its frequency
	cout << userString << " occurred " << itemFreq << " times." << endl;
}

/*
Description:
	Displays a list of items and '*' for each time that item was purchased that day.
Example:
	Apples ****
*/
void displayHistogram() {
	ifstream histFile("frequency.dat");
	string line;

	cout << "Reading file..." << endl;
	cout << endl;

	if (histFile.is_open()) {
		cout << "Displaying file..." << endl;
		cout << endl;
		while (getline(histFile, line)) {
			if (line.find(" 10") != string::npos){
					line.replace(line.find(" 10"), 2, " **********");
					cout << line << endl;
			}
			else if (line.find(" 2") != string::npos) {
					line.replace(line.find(" 2"), 2, " **");
					cout << line << endl;
			}
			else if (line.find(" 3") != string::npos) {
					line.replace(line.find(" 3"), 2, " ***");
					cout << line << endl;
			}
			else if (line.find(" 4") != string::npos) {
					line.replace(line.find(" 4"), 2, " ****");
					cout << line << endl;
			}
			else if (line.find(" 5") != string::npos) {
					line.replace(line.find(" 5"), 2, " *****");
					cout << line << endl;
			}
			else if (line.find(" 6") != string::npos) {
					line.replace(line.find(" 6"), 2, " ******");
					cout << line << endl;
			}
			else if (line.find(" 7") != string::npos) {
					line.replace(line.find(" 7"), 2, " *******");
					cout << line << endl;
			}
			else if (line.find(" 8") != string::npos) {
					line.replace(line.find(" 8"), 2, " ********");
					cout << line << endl;
			}
			else if (line.find(" 9") != string::npos) {
					line.replace(line.find(" 9"), 2, " *********");
					cout << line << endl;
			}
			else if (line.find(" 1") != string::npos) {
					line.replace(line.find(" 1"), 2, " *");
					cout << line << endl;
			}
			else {
					cout << "Error has occurred." << endl;
			}
		}
	}
	else {
		cout << "Unable to read file." << endl;
	}
}

/*
Description:
	Displays the main menu, requests user input to utilize program, and validates the user input.
Example:
	userInput == "1"  (This would generate a list of all items and the number of times they were purchased that day.
*/
void mainMenu() {
	string userInput;

	do {
		cout << "1: Generate a list of all items and the number of times each of those items were purchased today." << endl;
		cout << "2: Generate the number of times a specific item was purchased today." << endl;
		cout << "3: Generate a list of all items and a text-based histogram representing the number" << endl;
		cout << "   of times each of those items were purchased today." << endl;
		cout << "4: Exit program." << endl;
		cout << endl;
		cout << "Enter your selection as a number 1, 2, 3 or 4." << endl;
		cout << endl;

		cin >> userInput;

		if (userInput == "1") {
			CallProcedure("printItems");
			cout << endl;
		}
		else if (userInput == "2") {
			callItemFreq();
			cout << endl;
		}
		else if (userInput == "3") {
			callIntFunc("writeHistogram", 0);
			displayHistogram();
			cout << endl;
		}
		else if (userInput == "4") {
			cout << "Exiting program..." << endl;
			cout << endl;
		}
		else {
			cout << "Invalid entry. Please try again." << endl;
			cout << endl;
		}
	} while (userInput != "4");

}

int main()
{
	mainMenu();


	return 0;
}