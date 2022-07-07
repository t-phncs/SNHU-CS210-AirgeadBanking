#pragma once
#include <iostream>

using namespace std;

class CompoundInterest {
    //private data member 
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_interestRate;
    int m_numYears;
public:
    //default contructor, asking for user input
    CompoundInterest();
    // function to calculate closing balance from initial investment, monthly deposit, interest rate each year
    void balanceWithMonthlyDeposit();
    // function to calculate closing balance from initial investment, interest rate each year
    void balanceWithouthMonthlyDeposit();
    
    // function to display user input and result from balanceWithMonthlyDeposit() and balanceWithouthMonthlyDeposit()
    void display();
    // function to multiply char 
    string nCharString(size_t n, char c);
    //  function to make the program pause
    void pause();



};