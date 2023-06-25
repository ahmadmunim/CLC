#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "unary.h"
#include "operator.h"
#include "advanced.h"

float unaryOperation(int a) 
{
    char op;
    float n1 = 0;
    float advanced;

    if (a == 1) // ADVANCED OPTION 'A' IS SELECTED
    {
        advanced = advancedOp('U', n1, 0, op);
        memoryStore(advanced);
        printf("%f", advanced);
        return advanced;
    }

    else
    {
        do
        {
            do
            {
                while(getchar() != '\n');
                puts("Enter the first number: ");
            } while (scanf("%f", &n1) != 1);

            op = operatorSelection('U');

            if (n1 < 0 && (op == 'L' || op == 'l'))
                puts("You can't find the log of a negative number.");

        } while (n1 < 0 && (op == 'L' || op == 'l'));
      
        float result = unaryCalculation(n1, op);
        memoryStore(result);
        return result;  
    }
}

float unaryCalculation(float n1, char op)
{
  switch (op)
  {
    // a = 0; // ADVANCED OPTION RESETS TO ZERO IF THIS FUNCTION IS CALLED WITHIN THE ADVANCED OPERATION FUNCTION
    case 'S':
    case 's':
        printf("The root is: ");
        return sqrt(n1);
    case 'L':
    case 'l':
        printf("The logarithm is: ");
        return log10(n1);
    case 'E':
    case 'e':
        printf("The exponentation is: ");
        return exp(n1);
    case 'F':
    case 'f':
        printf("The floor is: ");
        return floor(n1);           
    case 'C':
    case 'c':
        printf("The ceiling is: ");
        return ceil(n1);           
  }
  return 0;
}