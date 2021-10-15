#ifndef AIRGEAD_BANKING_DATA_INPUT_H                               //Entering define guard
#define AIRGEAD_BANKING_DATA_INPUT_H

using namespace std;

/****************************************************************
 * This is the header file for data input menu to be displayed
 * at the beginning of the program.
 *
 * Authoer: Nicholas Phelps
 * Date: October 1, 2021
 ***************************************************************/

class DataInput {
public: 
    DataInput();              

    double GetInvestAmnt();                                        //Returns member's initial investment amount
    double GetMonthlyDeposit();                                    //Returns member's additional monthly deposit amount
    double GetAnnualInt();                                         //Returns member's annual interest rate
    int GetNumYears();                                             //Returns member's set number of years
    

    void SetInvestAmnt(double t_investAmnt);                       //Set member's initial investment amount
    void SetMonthlyDeposit(double t_depositAmnt);                   //Set member's additional monthly deposit amount
    void SetAnnualInt(double t_annualInt);                         //Set member's annual interest rate
    void SetNumYears(int t_numYears);                              //Set member's number of years
    
    void DisplayNoMonthly(void);                                   //Display without monthly deposits
    void DisplayWithMonthly(void);                                 //Display with monthly deposits

    //Functions to calculate the year end balances and interest with and without monthly deposits
    void CalcNoMonthly(double t_initialInvest, double& t_interestAmnt, double& t_finalAmnt);
    void CalcWithMonthly(double t_initialInvest, double& t_interestAmnt, double& t_finalAmnt);

    void PrintDataInput();                                         //Prints the default (blank) data input menu
    void PrintUserInput();                                         //Prints the data input menu with user values
    void PromptUser();                                             //Prompts user to input values

private:
    double m_investAmnt;
    double m_depositAmnt;
    double m_annualInt;
    int m_numYears;
    
};

#endif   //Ending define guard