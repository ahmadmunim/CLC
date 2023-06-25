#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "main.h"
#include "binary.c"
#include "unary.c"
#include "advanced.c"
#include "memory.c"
#include "numberSystems.c"

int counter = 0;

int main(void) {
    
    displayMsg();
        
    while (1)
    {
        char l = optionSelection();

        if (l == 'X' || l == 'x')
        {
            break;
        }


        switch(l) // ORGANIZES ALL THE OPTIONS AND CALLS THE APPROPRIATE FUNCTION 
        {
            case 'B':
            case 'b':
                printf("%f", binaryOperation(0)); 
                break;
            case 'U':
            case 'u':
                printf("%f", unaryOperation(0));
                break;
            case 'V':
            case 'v':
                varDeclaration();
                break;
            case 'A':
            case 'a':
                advancedOpSelection();
                break;
            case 'N':
            case 'n':
                numberSystemsOp();
                break;
            case 'M':
            case 'm':
                memoryView();
                break;
            // case 'R':
            // case 'r':
            //     memoryClear();
            //     break;
        }       
    }
}

void displayMsg() {
    puts("Welcome to my Command-Line Calculator (CLC)");
    puts("Developer: Ahmad Munim");
    puts("Version: 4");
    puts("Date: May 16th, 2022");
    puts("----------------------------------------------------");
    puts("Here are your options: ");
    puts("----------------------------------------------------");
    puts("B) Binary Mathematical Operations such as addition and subtraction.");
    puts("U) Unary Mathematical Operations, such as square root, and log.");
    puts("A) Advances Mathematical Operations, using variabless, arrays.");
    puts("N) Number Systems Operations (includes conversion and arithmetic)");
    puts("V) Define variables and assign them values.");
    puts("M) See the memory.");
    puts("R) Clear the memory.");
    puts("X) Exit"); 
}

char optionSelection() // VALIDATES THE USER'S INPUT WHEN SELECTING AN OPTION
{
    char l;

    while (1)
    {
        puts("\nSelect one of these operations (B, U, V, A, N, M, R, X): ");
        scanf(" %c", &l);

        if(l == 'X' || l == 'x') // EXITS THE PROGRAM
        {
            puts("Thanks for using my calculator.");
            return l;
        }

        switch(l)
        {
            case 'B':
            case 'b':
            case 'U':
            case 'u':
            case 'A':
            case 'a':
            case 'V':
            case 'v':
            case 'M':
            case 'm':
            case 'N':
            case 'n':
            // case 'R':
            // case 'r':
                return l; // RETURNS ANY OF THE ABOVE CASES FOR THE MAIN FUNCTION TO ORGANIZE
                break;
            default:
                puts("Invalid input. Please try again."); 
                continue;
        }
    }
}