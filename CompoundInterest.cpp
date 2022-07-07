#include <iostream>
#include <cmath>
#include <iomanip>
#include "CompoundInterest.h"

using namespace std;

//default constructor will ask for user input
CompoundInterest::CompoundInterest() {
    cout << nCharString(50, '*') << endl;
    cout << nCharString(20, '*') << " Data Input " << nCharString(18, '*') << endl;
    cout << "Initial Investment Amount: ";
    cin >> this->m_initialInvestment;
    cout << "Monthly Deposit: ";
    cin >> this->m_monthlyDeposit;
    cout << "Annual Interest: ";
    cin >> this->m_interestRate;
    cout << "Number of years: ";
    cin >> this->m_numYears;
    cout << endl;
}

string CompoundInterest::nCharString(size_t n, char c) {
    string str;
    str.append(n, c);
    return str;
}

void CompoundInterest::balanceWithMonthlyDeposit() {
    //this will be total balance 
    double amount = this->m_initialInvestment;
    // monthly compound interest
    double monthlyCI;
    //interest accrued 
    double inAccr;
    // assign monthly balance back to total balance 
    double mBal = amount;

    cout << "\tBalance and Interest With Additional Monthly Deposits" << endl;
    cout << nCharString(80, '=') << endl;
    cout << left << setw(10) << "Year" << setw(30) << "Year End Balance" << setw(35) << "Year End Earned Interest" << endl;
    cout << nCharString(80, '-') << endl;
    // 1st for loop for year
    for (int i = 1; i <= this->m_numYears; i++) {
        // need to initialize interest accrued back to 0 each year
        inAccr = 0.0;
        // 2nd for loop for month
        for (int j = 1; j <= 12; j++) {
            // monthly balance = initial balance + monthly deposit 
            mBal += this->m_monthlyDeposit;
            // monthly compound interest = initial balance + monthly deposit * (interest rate / 100 / 12)
            monthlyCI = mBal * ((this->m_interestRate / 100) / 12);
            // interest accrued each month + monthly interest
            inAccr += monthlyCI;
            // monthly balance + monthly interest
            mBal += monthlyCI;
        } //end 2nd for loop
        //total balance will be monthly balance  
        amount = mBal;
        cout << fixed << setprecision(2) << i << setw(15) << right << "$" << amount << setw(25) << "$" << inAccr << endl;
    } // 1st for loop
    cout << endl;
}
void CompoundInterest::pause() {
    cout << "Press any key to continue ..." << endl;
    cin.get();
    cin.ignore();
}

void CompoundInterest::balanceWithouthMonthlyDeposit() {
    double amount = this->m_initialInvestment;
    double inAccr;
    cout << "\tBalance and Interest Without Additional Monthly Deposits" << endl;
    cout << nCharString(80, '=') << endl;
    cout << left << setw(10) << "Year" << setw(30) << "Year End Balance" << setw(35) << "Year End Earned Interest" << endl;
    cout << nCharString(80, '-') << endl;
    // need only 1 loop to calculate since there's no deposit each month
    for (int i = 1; i <= this->m_numYears; i++) {
        // intest accrued each year = initial investment * intest rate / 100
        inAccr = amount * (this->m_interestRate / 100);
        // closing balance + intestest accrued 
        amount += inAccr;

        cout << fixed << setprecision(2);
        cout << i << " " << setw(15) << right << "$" << amount << setw(30) << "$" << inAccr << endl;
    }
    cout << endl;
}

void CompoundInterest::display() {
    //use setprecision and showpoint for trailing zero at 3 decimal on initial investment, 4 decimal on monthly deposit.
    cout << "Initial Investment Amount: " << "$" << setprecision(3) << showpoint << this->m_initialInvestment << endl;
    cout << "Monthly Deposit: " << "$" << setprecision(4) << this->m_monthlyDeposit << endl;
    //noshowpoint will stop trailing zero
    cout << "Annual Interest: " << "%" << noshowpoint << this->m_interestRate << endl;
    cout << "Number of years: " << this->m_numYears << endl;
    //calling pause function to make user press any key to continue
    pause();
    //set condition for monthly deposit
    //if monthly deposit > 0, 2 table will display 
    //if monthly deposit = 0, only 1 table display
    if (m_monthlyDeposit > 0) {
        balanceWithouthMonthlyDeposit();
        balanceWithMonthlyDeposit();
    }
    else {
        balanceWithouthMonthlyDeposit();
    }
    cout << endl;
}



