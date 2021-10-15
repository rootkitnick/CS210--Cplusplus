/* 
 * Calculator.cpp
 * 
 * Date: September 10, 2021
 * Author: Nicholas Phelps
 */
#include <iostream>

using namespace std;

int main() {                                                             //Moved the opening curly brace to the same line as the main() and changed type to int
    char statement[100];
    int op1, op2;
    char operation;
    char answer = 'y';                                                   //Added whitespace to increase readability, replaced "Y" with 'y'
                                                                         //This change was completed due to type char not string. Also added semicolon.

    while (answer == 'y') {                                              //Added whitespace and moved brace to same line to increase readability

        cout << "Enter expression" << endl;
        cin >> op1 >> operation >> op2;                                  //Swapped the positions of op1 and op2 so that user input would be in
                                                                         //the correct order

        if (operation == '+') {                                          //Replace the semicolon with curly brace, also changed "" to '' because looking for char not string
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;   //Replaced >> between op2 and " = " with <<
        }                                                                //Added end brace to the if statement
        else if (operation == '-') {                                     //Changed to if else statement and replaced semicolon with opening brace
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;   //Replaced >> between cout and op1 to <<
        }                                                                //Added end brace to the ifelse statement
        else if (operation == '*') {                                     //Changed to ifelse statement and added opening brace
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;   //Replaced " / " with " * " based on the ifelse argument to calculate correctly
        }                                                                //Added end brace to the ifelse statement
        else if (operation == '/') {                                     //Changed to ifelse statment and added an opening brace
            cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;   //Replaced " * " with " / " based on the ifelse argument to calculate correctly
        }                                                                //Added end brace to the ifelse statment
        else {                                                           //Added else statment to check for invalid user input
            cout << "Invalid Entry" << endl;
        }

        cout << "Do you wish to evaluate another expression?" << endl;
        cin >> answer;

    }
    
    return 0;                                                             //Added return of 0 to int main()
}