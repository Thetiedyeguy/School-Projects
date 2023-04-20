#include <stdio.h>
#include <string.h>

int binaryPossibilities(char binary[]) {
    for (int i = 0; i < strlen(binary); i++) {
        if (binary[i] == 'x' || binary[i] == 'X') {
            char possibility1[strlen(binary)], possibility2[strlen(binary)];
            strcpy(possibility1, binary);
            strcpy(possibility2, binary);
            possibility1[i] = '0';
            possibility2[i] = '1';
            binaryPossibilities(possibility1);
            binaryPossibilities(possibility2);
            return 0;
        }
    }
    printf("%s\n", binary);
    return 0;
}

int main(int argc, char* argv[]) {
    char binary[strlen(argv[1])];
    strcpy(binary, argv[1]);
    binaryPossibilities(binary);
    return 0;
}
