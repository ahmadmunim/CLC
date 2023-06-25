#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 8

#include "nsConversion.c"

void numberSystemsOp() {
    char l;
    
    setbuf(stdout, NULL);
    int x[MAX];
    int y[MAX];
    
    puts("Press \'c\' to convert or press \'a\' to perform arithmetic");
    scanf(" %c", &l);
    
    if (l == 'c') {
    
        char choice;
    
        puts("What number system would you like to enter? (b for binary, o for octal, h for hexadecimal)");
        scanf(" %c", &choice);
    
        switch (choice) {
            case 'b':
    
                printf("Enter the binary number: ");
    
                for (int i = 0; i < MAX; i++)
                {
                    do
                    {
                        printf("x%d = ", i + 1);
                        scanf("%d", &x[i]);

                        if (x[i] != 1 && x[i] != 0)
                            puts("Invalid input. Input the digit again"); 
                                            
                    } while (x[i] != 1 && x[i] != 0);               
                }  

                displayConversionPrompt(choice, x);

                break;
        }
    }
}