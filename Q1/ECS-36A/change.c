#include <stdio.h>
int main(void){
    int totalAmount;
    printf("Please enter the amount of money you wish to withdraw: ");
    scanf("%d", &totalAmount);
    printf("You received %d hundred(s)\n", totalAmount / 100);
    printf("You received %d fifty(s)\n", (totalAmount % 100) / 50);
    printf("You received %d twenty(s)\n", (totalAmount % 50) / 20);
    printf("You received %d ten(s)\n", ((totalAmount % 50)%20) / 10);
    printf("You received %d five(s)\n", (totalAmount % 10) / 5);
    printf("You received %d one(s)\n", (totalAmount % 5) / 1);
    return 0;
}
