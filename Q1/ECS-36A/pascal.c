#include <stdio.h>
int pascal(int iterations) {
    int triangle[iterations + 1];
    int placeholder[iterations + 1];
    for (int i = 0; i < iterations + 1; i++) {
        triangle[i] = 0;
        placeholder[i] = 0;
    }
    triangle[0] = 0;
    triangle[1] = 1;
    for (int i = 2; i < iterations + 2; i++) {
        for (int a = 1; a < i; a++) {
            placeholder[a] = triangle[a] + triangle[a - 1];
            printf("%d ", placeholder[a]);
        }
        for (int a = 0; a < iterations; a++) {
            triangle[a] = placeholder[a];
        }
        printf("\n");
    }
    return 0;
}

int main(void) {
    int iterations;
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf("%d", &iterations);
    pascal(iterations);
}
