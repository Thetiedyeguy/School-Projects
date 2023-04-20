#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int getCharAdress(char letter) {
    char *address;
    int index;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    address = strchr(alphabet, letter);
    index = (int)(address - alphabet);
    return index % 26;
}

bool compareStrings(char string1[100], char string2[100]) {
    int letters1[52];
    int letters2[52];

    for (int i = 0; i < 52; i++) {
        letters1[i] = 0;
        letters2[i] = 0;
    }

    for (int i = 0; i < strlen(string1); i++) {
        int index = getCharAdress(string1[i]);
        letters1[index] += 1;
    }
    for (int i = 0; i < strlen(string2); i++) {
        letters2[getCharAdress(string2[i])]++;
    }
    for (int i = 0; i < 52; i++) {
        if (letters1[i] != letters2[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    char string1[100];
    char string2[100];
    printf("Please enter the first word: ");
    scanf("%s", &string1);
    printf("Please enter the second word: ");
    scanf("%s", &string2);
    if (compareStrings(string1, string2)) {
        printf("%s is an anagram of %s\n", string1, string2);
    } else {
        printf("%s is NOT an anagram of %s\n", string1, string2);
    }
}
