#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int getInteger(char printStatement[]){
    int integer;
    printf("%s", printStatement);
    scanf("%d", &integer);
    return integer;
}

double draw(int *total, int drawAmount, int copies){
    double tempProbability = 1;
    for(int i = 0; i < drawAmount; i++){
        tempProbability = tempProbability * (1 - ((double) copies / (double) *total));
        *total = *total - 1;
    }
    return tempProbability;
}

int main(void){
    int totalCards, copies, handSize, mulliganAmt, turn;
    double probability = 1;
    totalCards = getInteger("Enter how many total cards there are in the deck: ");
    copies = getInteger("Enter how many copies of the card that you are looking for are in the deck: ");
    handSize = getInteger("Enter your initial hand size: ");
    mulliganAmt = getInteger("Enter how many cards you are mulliganing: ");
    turn = getInteger("Enter what turn you want to draw the card by: ");
    probability = probability * draw(&totalCards, handSize, copies);
    probability = probability * draw(&totalCards, mulliganAmt, copies);
    totalCards = totalCards + mulliganAmt;
    probability = probability * draw(&totalCards, turn, copies);
    printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is %.2lf\n", turn, mulliganAmt, (1 - probability));
}
