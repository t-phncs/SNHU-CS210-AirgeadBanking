#include <iostream>
#include "CompoundInterest.h"

using namespace std;

int main() {
	// declare variable and initialize it
	double initialInvestment{};
	double monthlyDeposit{};
	double interestRate{};
	int numYears{};
	//create an object named ci
	//since we have a default contructor, no need to add any arguments
	CompoundInterest ci;
	//calling display function to print user input and the result from balance with deposit function and without deposit function
	ci.display();

	return 0;


}