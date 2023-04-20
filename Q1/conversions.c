#include <stdio.h>
#include <math.h>
#include <ctype.h>

char conversionType(){
    char conversionChoice;
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");
    scanf("%c", &conversionChoice);
    return tolower(conversionChoice);
}

int temperatureConversion(){
    double temperature = 12;
    char originalUnits = 'k';
    char finalUnits = 'f';
    printf("Enter the temperature followed by its suffix (F, C, or K): ");
    scanf("%lf%c", &temperature, &originalUnits);
    printf("Enter the new unit type (F, C, or K): ");
    scanf("%c", &finalUnits);
    originalUnits = tolower(originalUnits);
    finalUnits = tolower(finalUnits);
    if (originalUnits == 'f') {
        if (finalUnits == 'c') {
            temperature = (temperature - 32) * (5/9);
        }else if(finalUnits == 'k'){
            temperature = ((temperature - 32) * (5/9)) + 273.15;
        }
    }else if(originalUnits == 'c'){
        if(finalUnits == 'f'){
            temperature = (temperature * (9/5)) + 32;
        }else if(finalUnits == 'k'){
            temperature = temperature + 273.15;
        }
    }else if(originalUnits == 'k'){
        if(finalUnits == 'c'){
            temperature = temperature - 273.15;
        }else if(finalUnits == 'f'){
            temperature = ((temperature - 273.15) * (9/5)) + 32;
        }
    }
    return 0;
}

int distanceConversion(){
    return 0;
}

int main (){
    char conversionChoice = conversionType();
    if(conversionChoice == 't'){
        temperatureConversion();
    }else if(conversionChoice == 'd'){
        distanceConversion();
    }else{
        printf("Unknown conversion type %c chosen. Ending Program.\n");
    }
    return 0;
}
