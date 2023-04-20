#include <stdio.h>
#include <math.h>
int main(void){
    double amt_borrowed;
    double interestRate;
    int num_payments;
    double payment;
    double totalPayment;


    printf("Please enter the amount of money you borrowed: ");
    scanf("%lf", &amt_borrowed);
    printf("$Please enter the annual interest rate: ");
    scanf("%lf", &interestRate);
    printf("Please enter the number of payments to be made: ");
    scanf("%d", &num_payments);

    payment = ((interestRate / 12) * amt_borrowed) / (1 - pow(1 + (interestRate / 12), -num_payments));
    printf("A loan of $%.2lf with an annual interest of %.2lf payed off over %d months will have monthly payments of $%.2lf.\n", amt_borrowed, interestRate, num_payments, payment);
    totalPayment = payment * num_payments;
    printf("In total you will pay $%.2lf, making the cost of your loan $%.2lf.\n", totalPayment, totalPayment - amt_borrowed);

}
