#include <stdio.h>

int foo(int n, int* previousSolutions) {
    if (n == 0) {
        return 3;
    } else if (n == 1) {
        return 6;
    } else if (n == 2) {
        return 2;
    }else if (n == 3){
        return 7;
    } else {
        previousSolutions[n] = foo(n - 1, previousSolutions) + previousSolutions[n - 2] + previousSolutions[n - 3] - previousSolutions[n - 4] + 1;
        return previousSolutions[n];
    }
}

int main() {
    int n;
    printf("Enter a value for n: ");
    scanf("%d", &n);
    int previousSolutions[n];
    previousSolutions[0] = 3;
    previousSolutions[1] = 6;
    previousSolutions[2] = 2;
    previousSolutions[3] = 7;
    printf("Foo(%d) = %d\n", n, foo(n, previousSolutions));
    return 0;
}
