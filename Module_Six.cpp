#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print the exit message to screen: "Exiting program..."
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
	To call this function, pass the name of the Python function you wish to call and the integer parameter you want to send
Example:
	int x = callIntFunc("DoubleValue",5); or int x = callIntFunc("MultiplicationTable", userNum);
Return:
	25 is returned to the C++ or a multiplication table of userNum * 1 through 10
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
	To display a menu with options to display a multiplication table, double a value, or 
	exit the program.
Example:
	1: Display a Multiplication Table
	2: Double a Value
	3: Exit
	Enter your selection as a number 1, 2, or 3.
Return:
	None
*/
void mainMenu() {

	cout << "1: Display a Multiplication Table" << endl;
	cout << "2: Double a Value" << endl;
	cout << "3: Exit" << endl;
	cout << "Enter your selection as a number 1, 2, or 3." << endl;
	cout << endl;

}

/*This is the main function which declare two local variables, displays a main menue, and calls
  functions defined in python before returning the results to C++ and displaying those results.*/
int main() {
	int menuNum;   //local variable used to get which menu function to call
	int userNum;   //local variable used to call the multiplication table or double value functions
	
	//A do while loop that will continue to display the main menu until user enters 3
	do {
		mainMenu();
		cin >> menuNum; 

		//Determines if the user entered a character instead of a integer and exits program if true
		if (cin.fail()) {
			cin.clear();
			cout << "Invalid entry. Exiting program..." << endl;
			break;
		}

		while (!cin.fail()) {
			//Calls the multiplication table function from python and displays it in C++
			if (menuNum == 1) {
				cout << "Enter a number to be multiplied: " << endl;
				cin >> userNum;
				cout << callIntFunc("MultiplicationTable", userNum);
				cout << endl;
				break;
			}
			//Calls the double value function from python and displays it in C++
			else if (menuNum == 2) {
				cout << "Enter a number to be doubled: " << endl;
				cin >> userNum;
				cout << callIntFunc("DoubleValue", userNum) << endl;
				cout << endl;
				break;
			}
			//Calls the exit program function from python and displays it in C++
			else if (menuNum == 3) {
				CallProcedure("exitprogram");
				cout << endl;
				break;
			}
			//Prints an error message is user enters an invalid interger
			else {
				cout << "Invalid entry. Please try again." << endl;
				cout << endl;
			}
		}
	} while (menuNum != 3);


	return 0;
}