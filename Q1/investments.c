#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int getInteger(char printStatement[]) {
    int integer;
    bool isInteger = false;
    while (!isInteger || !(integer > 0)) {
        printf("%s", printStatement);
        if (!scanf("%d", &integer)) {
            scanf("%*[^\n]");
        } else {
            isInteger = true;
        }
    }
    return integer;
}

double getDouble(char printStatement[]) {
    double doubleNumber;
    bool isDouble = false;
    while (!isDouble || !(doubleNumber > 0)) {
        printf("%s", printStatement);
        if (!scanf("%lf", &doubleNumber)) {
            scanf("%*[^\n]");
        } else {
            isDouble = true;
        }
    }
    return doubleNumber;
}
double calculatePayments(double investment, double loans, double interestRate, double minimum, int currentAge,
                        int currentAgeMonths, int retirementAge, int retirementAgeMonths, double returnRate, int amountOfMonths) {
  double savedMoney = 0;
  double leftover;
  for (int i = 0; i < amountOfMonths; ++i) {
    loans += (loans * (interestRate / 12));
    savedMoney = savedMoney + (savedMoney * (returnRate / 12));

    if ((loans - minimum) < 0) {
      savedMoney = savedMoney - loans;
      loans = 0;
      leftover = investment;
    } else {
      loans = loans - minimum;
      leftover = investment - minimum;
    }

    savedMoney = savedMoney + leftover;
  }
  return savedMoney;
}

double calculateMaximumPayments(double investment, double loans, double interestRate, int currentAge,
                                int currentAgeMonths, int retirementAge, int retirementAgeMonths, double returnRate, int amountOfMonths) {
    double savedMoney = 0;
    for (int i = 0; i < amountOfMonths; ++i) {
        if (loans > 0) {
            loans += (loans * (interestRate / 12));
            if ((loans - investment) < 0) {
                savedMoney = investment - loans;
                loans = 0;
            } else {
                loans = loans - investment;
            }
        } else {
            savedMoney = savedMoney + (savedMoney * (returnRate / 12));
            savedMoney = savedMoney + investment;
        }
    }
    if (loans > 0) {
        printf("Warning! After you retire you will still have $%.2lf in loans left.\n", loans);
    }
    return savedMoney;
}


int main(void) {
    double investment, loans, interestRate, minimum, returnRate, savedMoneyMinimum, savedMoneyMaximum;
    int currentAge, retirementAge, currentAgeMonths, retirementAgeMonths, amountOfMonths;
    investment = getDouble("Enter how much money you will be putting towards loans/retirement each month: ");
    loans = getDouble("Enter how much you owe in loans: ");
    interestRate = getDouble("Enter the annual interest rate of the loans: ");
    minimum = getDouble("Enter your minimum monthly loan payment: ");
    if (investment < minimum) {
        printf("You didn't set aside enough money to pay off our loans. Ending program.");
        return 0;
    }
    currentAge = getInteger("Enter your current age: ");
    currentAgeMonths = currentAge * 12;
    retirementAge = getInteger("Enter the age you plan to retire at: ");
    retirementAgeMonths = retirementAge * 12;
    returnRate = getDouble("Enter the annual rate of return you predict for your investments: ");
    amountOfMonths = retirementAgeMonths - currentAgeMonths;
    savedMoneyMinimum = calculatePayments(investment, loans, interestRate, minimum, currentAge,
                                            currentAgeMonths, retirementAge, retirementAgeMonths, returnRate, amountOfMonths);
    savedMoneyMaximum = calculateMaximumPayments(investment, loans, interestRate, currentAge,
                                                currentAgeMonths, retirementAge, retirementAgeMonths, returnRate, amountOfMonths);
    if (savedMoneyMinimum > savedMoneyMaximum) {
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have");
        printf(" $%.2lf when you retire as opposed to $%.2lf if you payed off your loan before investing.\n", savedMoneyMinimum, savedMoneyMaximum);
    } else {
        printf("You should apply all $%.2lf towards your loan before making any investments.\n", investment);
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.\n", savedMoneyMaximum, savedMoneyMinimum);
    }
}
