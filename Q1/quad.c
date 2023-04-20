#include <stdio.h>
#include <math.h>

int printEquation(){
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    return 0;
}

double getInput(char letter){
    double number;
    printf("Please enter %c: ", letter);
    scanf("%lf", &number);
    return number;
}

int solve(double a, double b, double c){
    double solution1;
    double solution2;

    if (((b * b) - 4.0 * (a * c)) < 0){
        printf("There are no real solutions\n");
        return 0;
    } else{
        solution1 = ((-1.0 * b) + sqrt((b * b) - (4.0 * a * c))) / (2.0 * a);
        solution2 = ((-1.0 * b) - sqrt((b * b) - (4.0 * a * c))) / (2.0 * a);
    }
    
    if (solution1 == solution2){
        printf("There is one real solution: %.2lf\n", solution1);
        return 0;
    } else{
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", solution1);
        printf("Solution 2: %.2lf\n", solution2);
        return 0;
    }
}

int main(){
    double a, b, c;
    printEquation();
    a = getInput('a');
    b = getInput('b');
    c = getInput('c');
    solve(a, b, c);
    return 0;
}
