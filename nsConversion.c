#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "nsConversion.h"

#define MAX 8

void displayConversionPrompt(char optionSelected, int result[]) {
    if (optionSelected == 'b') {
        
        char convertTo;
        
        puts("What number system would you like to convert this to? (o for octal, d for decimal, h for hexadecimal)");
        scanf("  %c", &convertTo);
        
        switch (convertTo) {
            case 'o':
                binaryToOctal(result);
                break;
            case 'd':
                binaryToDecimal(result);
                break;
            case 'h':
                binaryToHexadecimal(result);
                break;
        }
    }
}

void binaryToOctal(int result[])
{
    int sum = 0;
    int power = 0;

    if (result[0] == 1) // Means the binary number is negative
        sum = -128;

    else
        sum = 0;

    for (int i = MAX - 1; i > 0; i--)
        sum = sum + (result[i] * pow(2, power++));

    printf("%o in octal\n", sum);
}

void binaryToDecimal(int result[])
{
    int sum = 0;
    int power = 0;

    if (result[0] == 1)
        sum = -128;

    else
        sum = 0;

    for (int i = MAX - 1; i > 0; i--)
        sum = sum + (result[i] * pow(2, power++));

    printf("%d in decimal\n", sum);    
}

void binaryToHexadecimal(int result[])
{
    int sum = 0;
    int power = 0;

    if (result[0] == 1)
        sum = -128;

    else
        sum = 0;

    for (int i = MAX - 1; i > 0; i--)
        sum = sum + (result[i] * pow(2, power++));

    printf("%x in hexadecimal\n", sum);   
}