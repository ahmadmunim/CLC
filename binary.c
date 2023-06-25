#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "binary.h"
// #include "main.h"
#include "memory.h"
#include "advanced.h"
#include "operator.h"

float binaryOperation(int a)
{
    float n1 = 0;
    float n2 = 0;
    char op;
    float advanced;

    if (a == 1) // ADVANCED OPTION 'A' IS SELECTED
    {
        advanced = advancedOp('B', n1, n2, op);
        printf("%f", advanced); // DISPLAYS THE RESULT OF THE CALCULATION 
        // memoryStore(advanced);
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

            op = operatorSelection('B');

            do
            {
                do
                {
                    while (getchar() != '\n');
                    puts("Enter the second number: ");
                } while (scanf("%f", &n2) != 1);
                  
                if (n2 == 0 && op == '/')
                    puts("Can't divide by 0.");
                    
            } while (n2 == 0 && op == '/');       

            if (n1 == 0 && n2 == 0 && op == '^')
                puts("0^0 is undefined");
            
        } while (n1 == 0 && n2 == 0 && op == '^');
    
    float result = binaryCalculation(n1, op, n2);
    memoryStore(result);
    return result;
    }
}

float binaryCalculation(float n1, char op, float n2) // TWO FUNCTIONS BELOW ORGANIZES THE POTENTIAL OPERATIONS AND SELECTS THE APPROPRIATE ONE TO RETURN A VALUE
{
  switch (op)
  {
    // a = 0; // ADVANCED OPTION RESETS TO ZERO IF THIS FUNCTION IS CALLED WITHIN THE ADVANCED OPERATION FUNCTION
    case '+':
      printf("The sum is: ");
      return n1+n2;
    case '-':
      printf("The difference is: ");
      return n1-n2;           
    case '*':
      printf("The product is: ");
      return n1*n2;           
    case '/':
      printf("The quotient is: ");
      return n1/n2;                      
    case '^':
      printf("The power is: ");
      return pow(n1, n2);                      
    case '%':
      printf("The remainder is: ");
      return (int)n1 % (int)n2; 
    case 'x':
      printf("The max is: ");
      return n1 >= n2 ? n1 : n2; // THE FIRST NUMBER IS OUTPUTTED IF IT'S GREATER THEN THE SECOND ONE. VICE-VERSA OTHERWISE
    case 'i':
      printf("The min is: ");
      return n1 >= n2 ? n2 : n1;               
  }
  return 0;
}