#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

double randomNumber() {
    return -1 + ((double) rand()) / (((double) RAND_MAX) / (1 + 1));
}

double calculateProbability(int iterations) {
    int numInCircle = 0;
    for (int i = 0; i < iterations; i++) {
        double x, y;
        x = randomNumber();
        y = randomNumber();
        if (sqrt((x * x) + (y * y)) < 1) {
            numInCircle++;
        }
    }
    return (numInCircle / (double)iterations);
}

int getSeed() {
    int seed;
    bool isInteger = false;
    while (!isInteger) {
        printf("Enter the seed for the random number generator: ");
        if (!scanf("%d", &seed)) {
            scanf("%*[^\n]");
        } else {
            isInteger = true;
        }
    }
    return seed;
}

int getIterations() {
    int iterations;
    bool isInteger = false;
    while (!isInteger) {
        printf("Enter the number of iterations to run: ");
        if (!scanf("%d", &iterations)) {
            scanf("%*[^\n]");
        } else {
            isInteger = true;
        }
    }
    return iterations;
}

int main(void) {
    double probability, pi;
    int seed, iterations;
    seed = -1;
    iterations = -1;
    seed = getSeed();
    srand(seed);
    while (iterations <= 0) {
        iterations = getIterations();
    }
    probability = calculateProbability(iterations);
    pi = probability * 4;
    printf("The value of pi is %.3lf.\n", pi);
    return 0;
}
