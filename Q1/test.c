#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int final;
    char c[100];
    scanf("%[^\n]%*c", &c);
    for(int i = 0; i < strlen(c);i++){
        if(isdigit(c[i]) == 0){
            printf("no");
            return 0;
        }
    }
    final = atoi(c);
    printf("%d", final - 12);
    return 0;
}
