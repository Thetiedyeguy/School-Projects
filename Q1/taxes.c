#include <stdio.h>
#include <math.h>

int percentCalculator (double income){
    double caps[7] = {9875, 40125, 85525, 163300, 207350, 518400, 999999999999};
    double rates[7] = {0.10, 0.12, 0.22, 0.24, 0.32, 0.35, 0.37};
    double taxTotal;
    taxTotal = 0;
    for (int i = 0; i < 7; i++){
        if (income >= caps[i]){
            if (i == 0){
                taxTotal += caps[i] * rates[i];
                printf("You were taxed %.2lf%% on the first $%.2lf you made which is $%.2lf.\n",
                rates[i] * 100, caps[i], rates[i] * caps[i]);
            }else{
                taxTotal += (caps[i] - caps[i - 1]) * rates[i];
                printf("You were taxed %.2lf%% on the next $%.2lf you made which is $%.2lf.\n",
                rates[i] * 100, caps[i] - caps[i - 1], rates[i] * (caps[i] - caps[i - 1]));
            }
        }else{
            if (i == 0){
                taxTotal += income * rates[i];
                printf("You were taxed %.2lf%% on the first $%.2lf you made which is $%.2lf.\n",
                rates[i] * 100, income, rates[i] * income);
            }else if (income >= caps[i - 1]){
                taxTotal += (income - caps[i - 1]) * rates[i];
                printf("You were taxed %.2lf%% on the next $%.2lf you made which is $%.2lf.\n",
                rates[i] * 100, income - caps[i - 1], rates[i] * (income - caps[i - 1]));
            }
        }
    }
    printf("In total you will pay $%.2lf in taxes on the $%.2lf you made this year.\n", taxTotal, income);
    printf("This would amount to a FLAT tax of %.2lf%% on all of your income.\n", (taxTotal / income) * 100);
    return 0;
}

int main(){
    double income;
    printf("Enter your income for the year: ");
    scanf("%lf", &income);
    percentCalculator(income);
    return 0;
}
