#include <stdio.h>
int main(void){
    char letterGrade;
    double wantedGrade;
    double currentGrade;
    double finalWeight;
    double neededGrade;
    printf("Enter the grade you want in the class: ");
    scanf("%c", &letterGrade);
    printf("Enter the percent you need to get that grade: ");
    scanf("%lf", &wantedGrade);
    printf("Enter your current percent in the class: ");
    scanf("%lf", &currentGrade);
    printf("Enter the weight of the final: ");
    scanf("%lf", &finalWeight);

    neededGrade = (wantedGrade - (1 - (finalWeight / 100)) * currentGrade) / (finalWeight / 100);

    printf("You need to get at least %.2lf%% on the final to get a %c in the class.\n", neededGrade, letterGrade);
    return 0;
}
