#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    int imaginary_one, imaginary_two, imaginary_total, real_one, real_two, real_total;
    printf("Enter the first complex number in the form ai + b: ");
    scanf("%di + %d", &imaginary_one, &real_one);
    printf("Enter the second complex number in the form ai + b: ");
    scanf("%di + %d", &imaginary_two, &real_two);

    imaginary_total = (imaginary_one * real_two) + (imaginary_two * real_one);
    real_total = (real_one * real_two) - (imaginary_one * imaginary_two);
    printf("(%di + %d) * (%di + %d) = %di + %d \n", imaginary_one, real_one, imaginary_two, real_two, imaginary_total, real_total);


}
