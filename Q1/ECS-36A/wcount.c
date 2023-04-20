#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE *input;
    int numWords = 0;
    char c;
    input = fopen(argv[1], "r");
    int previousIsSpace = 0;
    while (1) {
        c = fgetc(input);
        if (feof(input)) {
            break;
        }
        if ((c == ' ' || c == '\n') && !previousIsSpace) {
            numWords++;
            previousIsSpace = 1;
        }else{
            previousIsSpace = 0;
        }
    }
    printf("There are %d word(s).\n", numWords);

}
