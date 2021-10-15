#ifndef AIRGEAD_BANKING_INVESTMENT_H
#define AIRGEAD_BANKING_INVESTMENT_H

#include <vector>

using namespace std;

/************************************************************************************************************************
 * This is the header file for the investement data including vectors for years, year end 
 * balances, and year end earned interest. 
 * Source: Jef DeWitt.(March 28, 2020)."https://github.com/SNHU-projects/airgead-banking/blob/master/InvestmentInfo.h"
 *
 * Modified by: Nicholas Phelps
 * Date: October 2, 2021
 ***********************************************************************************************************************/

class Investment {
public: 
	Investment();                                     //Default constructor
	
	vector<int>& GetYears();                          //Vector used to hold and get number of years
	vector<int>& GetYearEndBal();                     //Vector used to hold and get year end balances
	vector<int>& GetYearEarnInt();                    //Vector used to hold and get year end earned interest amount

	void SetYears(vector<int>& t_years);              //Sets year in vector
	void SetYearEndBal(vector<int>& t_yearEndBal);    //Sets year end balance in vector
	void SetYearEarnInt(vector<int>& t_yearEarnInt);  //Sets year end earned interest amount in vector

private:
	vector<int> m_years;
	vector<int> m_yearEndBal;
	vector<int> m_yearEarnInt;

};
#endif