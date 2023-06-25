#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char operatorSelection(char l) // ASKS THE USER TO ENTER AN OPERATION AND VALIDATES THE INPUT DEPENDING ON THE OPTION (B or U) SELECTED
{
    char op;

    switch(l)
    {
        case 'B':
        case 'b':
            do
            {
                while (getchar() != '\n');                
                puts("Enter an operation (+, -, *, /, ^, % (remainder), x (max), i (min): ");
            } while (scanf("%c", &op) != 1 || (op != '+' && op != '-' && op != '*' && op != '/' && op != '^' && op != '%' && op != 'x' && op != 'i'));
            return op;
        case 'U':
        case 'u':
            do
            { 
                while (getchar() != '\n');             
                puts("Enter an operation (s for root, l for logarithm, e for exponentation, f for floor, c or ceiling): ");
            } while (scanf("%c", &op) != 1 || (op != 'S' && op != 'L' && op != 'E' && op != 'F' && op != 'C' && op != 's' && op != 'l' && op != 'e' && op != 'f' && op != 'c'));
            return op;                     
    }
    return 0;
}