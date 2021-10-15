#include <iostream>
#include <iomanip>
#include "Data_Input.h"

using namespace std;

/*********************************************************************
 * This file will contain the member function definitions for the
 * Data_Input.h file. This will be where the primary getters and
 * setters for user input will be held.
 *
 * Author: Nicholas Phelps
 * Date: October 1, 2021
 *********************************************************************/

//Default constructor 
DataInput::DataInput() {
}

//Getters
double DataInput::GetInvestAmnt() { return m_investAmnt; }

double DataInput::GetMonthlyDeposit() { return m_depositAmnt; }

double DataInput::GetAnnualInt() { return m_annualInt; }

int DataInput::GetNumYears() { return m_numYears; }



//Setters
void DataInput::SetInvestAmnt(double t_investAmnt) {
    m_investAmnt = t_investAmnt;
}

void DataInput::SetMonthlyDeposit(double t_depositAmnt) {
    m_depositAmnt = t_depositAmnt;
}

void DataInput::SetAnnualInt(double t_annualInt) {
    m_annualInt = t_annualInt;
}

void DataInput::SetNumYears(int t_numYears) {
    m_numYears = t_numYears;
}

//Prints the default data input menu, checks user input for quit command before prompting user to input values
void DataInput::PrintDataInput() {
    char userInput;

    cout << string(34, '*') << endl;
    cout << string(10, '*') << "  Data Input  " << string(10, '*') << endl;
    cout << "Initial Investment Amount: " << endl;
    cout << "Monthly Deposit: " << endl;
    cout << "Annual Interest: " << endl;
    cout << "Number of Years: " << endl;
    cout << "Press any key to continue..." << endl;
    cout << endl;

    cin >> userInput;
    if (userInput != 'q') {
        DataInput::PromptUser();
    }
    else {
        cout << "Exiting program..." << endl;
    }
}

//Displays the data input menu with user values entered
void DataInput::PrintUserInput() {
    string userInput;

    cout << string(34, '*') << endl;
    cout << string(10, '*') << "  Data Input  " << string(10, '*') << endl;
    cout << "Initial Investment Amount: $" << GetInvestAmnt() << endl;
    cout << "Monthly Deposit: $" << GetMonthlyDeposit() << endl;
    cout << "Annual Interest: %" << GetAnnualInt() << endl;
    cout << "Number of Years: " << GetNumYears() << endl;
    cout << endl;
}

//Prompts user to input values
void DataInput::PromptUser() {
    double investAmnt;
    double monDeposit;
    int numYears;
    double annualInt;

    cout << "Enter initial investment amount: " << endl;
    cin >> investAmnt;
    SetInvestAmnt(investAmnt);
    cin.ignore();

    cout << "Enter additional monthly deposits: " << endl;
    cin >> monDeposit;
    SetMonthlyDeposit(monDeposit);
    cin.ignore();

    cout << "Enter annual interest rate: " << endl;
    cin >> annualInt;
    SetAnnualInt(annualInt);
    cin.ignore();

    cout << "Enter number of years: " << endl;
    cin >> numYears;
    SetNumYears(numYears);
    cin.ignore();
}

//Calculates the year end balance and interest WITH monthly deposits
void DataInput::CalcWithMonthly(double t_initialInvest, double& t_interestAmnt, double& t_finalAmnt) {
    t_interestAmnt = 0.0;
    t_finalAmnt = t_initialInvest;

    for (int month = 0; month < 12; ++month) {
        t_finalAmnt += m_depositAmnt;
        double monthlyInterestAmnt = t_finalAmnt * ((m_annualInt / 100.0) / 12.0);
        t_finalAmnt += monthlyInterestAmnt;
        t_interestAmnt += monthlyInterestAmnt;
    }
}

//Calculates the year end balance and interest WITHOUT monthly deposits
void DataInput::CalcNoMonthly(double t_initialInvest, double& t_interestAmnt, double& t_finalAmnt) {
    t_interestAmnt = 0.0;
    t_finalAmnt = t_initialInvest;

    for (int month = 0; month < 12; ++month) {
        double monthlyInterestAmnt = t_finalAmnt * ((m_annualInt / 100.0) / 12.0);
        t_finalAmnt += monthlyInterestAmnt;
        t_interestAmnt += monthlyInterestAmnt;
    }
}

//Displays the year end balances and interest WITH monthly deposits
void DataInput::DisplayWithMonthly() {

    int i;
    int currYears;
    double currInvest;
    double currInterest;
    double yearEndSum;

    currYears = m_numYears;
    currInvest = m_investAmnt;
    currInterest = m_annualInt;

    cout << "   Balance and Interest With Additional Monthly Deposits     " << endl;
    cout << string(62, '=') << endl;
    cout << "    Year        Year End Balance     Year End Earned Interest   " << endl;
    cout << string(62, '-') << endl;

    for (i = 1; i <= currYears; ++i) {
        CalcWithMonthly(currInvest, currInterest, yearEndSum);
        currInvest = yearEndSum;

        cout << "     " << i << "                  $";
        cout << setprecision(2) << fixed << yearEndSum << "                        ";
        cout << setprecision(2) << fixed << currInterest << endl;
    }
}

//Displays the year end balances and interest WITHOUT monthly deposits
void DataInput::DisplayNoMonthly() {
    int i;
    int currYears;
    double currInvest;
    double currInterest;
    double yearEndSum;

    currYears = m_numYears;
    currInvest = m_investAmnt;
    currInterest = m_annualInt;

    cout << "   Balance and Interest Without Additional Monthly Deposits     " << endl;
    cout << string(62, '=') << endl;
    cout << "    Year        Year End Balance     Year End Earned Interest   " << endl;
    cout << string(62, '-') << endl;

    for (i = 1; i <= currYears; ++i) {
        CalcNoMonthly(currInvest, currInterest, yearEndSum);
        currInvest = yearEndSum;

        cout << "     " << i << "                  $";
        cout << setprecision(2) << fixed << yearEndSum << "                        ";
        cout << setprecision(2) << fixed << currInterest << endl;
    }
}