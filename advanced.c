#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "operator.h"
#include "advanced.h"
#include "main.h"
#include "binary.h"
#include "unary.h"

static float values[5];

void varDeclaration() // ASKS THE USER TO ASSIGN A VALUE TO A VARIABLE (a to e)
{  
    char var;
    float n1; 

    do
    {
        do
        {
            while (getchar() != '\n');
            puts("Enter a letter (a to e) or press x to exit");
        } while (scanf("%c", &var) != 1 || (var != 'a' && var != 'b' && var != 'c' && var != 'd' && var != 'e' && var != 'x'));

        if (var == 'x')
            break;

        do
        {
            while (getchar() != '\n');
            puts("Enter a number: ");
        } while (scanf("%f", &n1) != 1);
        
        values[var - 'a'] = n1; // ASCII VALUES FOR CHARACTERS ARE USED TO GET AN INDEX TO STORE THE VALUE

        printf("%c = %f\n", var, n1);   
    } while (var != 'x');
}

void advancedOpSelection()
{     
    char l;
    do
    {
      while (getchar() != '\n');
      puts("Enter one of these letters (B, U, X)");
    } while (scanf("%c", &l) != 1 || (l != 'B' && l != 'b' && l != 'U' && l != 'u' && l != 'X' && l != 'x'));
    
    switch(l) // CALLS THE APPROPRIATE FUNCTION TO DO THE ADVANCED OPERATION WITH VARIABLES
    {
      case 'B':
      case 'b':
        binaryOperation(1);
        break;
      case 'U':
      case 'u':
        unaryOperation(1);
        break;
    }
}

float advancedOp(char l, float n1, float n2, char op)
{ 
  char var;
  char selection;

  if (l == 'B') // IF THE USER WANTS TO DO A BINARY OPERATION WITH VARIABLES
  {
    do
    {
      while (getchar() != '\n');
      puts("Press 'v' to enter two letters or 't' to enter a variable and a number: "); // ASKS THE USER IF THE USER WANTS THE PROGRAM TO CALCULATE WITH TWO VARIABLES OR
                                                                                        // ONE VARIABLE AND ONE NUMBER
    } while (scanf("%c", &selection) != 1 || (selection != 't' && selection != 'T' && selection != 'v' && selection != 'V'));
    
    switch(selection)
    {
      case 'V': // AKS THE USER TO ENTER THE ACCEPTED TWO LETTERS FROM a TO e AND AN OPERATOR
      case 'v':
        do
        {
            while (getchar() != '\n');
            puts("Enter a variable (a to e): ");
        } while (scanf("%c", &var) != 1 || (var != 'a' && var != 'b' && var != 'c' && var != 'd' && var != 'e'));

        n1 = values[var - 'a']; // STORES THE CORRESONDING VALUE TO THE INPUTTED VARIABLE USING THE ASCII VALUES OF THE VARIABLES IN n1

        op = operatorSelection('B');

        do
        {
            while (getchar() != '\n');
            puts("Enter a variable (a to e): ");
        } while (scanf("%c", &var) != 1 || (var != 'a' && var != 'b' && var != 'c' && var != 'd' && var != 'e'));

        n2 = values[var - 'a'];
        float result = binaryCalculation(n1, op, n2);
        return result;
    case 'T':
    case 't':
      do
      {
        while (getchar() != '\n');
        puts("What do you want to enter first? ('v' for variable, 'n' for number: "); // ASKS THE USER IF THE USER WANTS TO ENTER A VARIABLE OR A NUMBER FIRST
      } while (scanf("%c", &selection) != 1 || (selection != 't' && selection != 'T' && selection != 'v' && selection != 'V'));

      if (selection == 'v') // IF THE USER WANTS TO ENTER A VARIABLE FIRST
      {
        do
        {
            while (getchar() != '\n');
            puts("Enter a variable (a to e): "); // ASKS FOR A VARIABLE FIRST
        } while (scanf("%c", &var) != 1 || (var != 'a' && var != 'b' && var != 'c' && var != 'd' && var != 'e'));

        n1 = values[var - 'a'];

        op = operatorSelection(l);

        do
        {
          while (getchar() != '\n');
          puts("Enter a number: ");
        } while (scanf("%f", &n2) != 1);
        return binaryCalculation(n1, op, n2);     
      }
      else
      {
        do
        {
          while (getchar() != '\n');
          puts("Enter a number: ");
        } while (scanf("%f", &n1) != 1);

        op = operatorSelection(l);

        do
        {
          while (getchar() != '\n');
          puts("Enter a variable (a to e): ");
        } while (scanf("%c", &var) != 1 || (var != 'a' && var != 'b' && var != 'c' && var != 'd' && var != 'e'));

        n2 = values[var - 'a'];
        float result = binaryCalculation(n1, op, n2);
        return result;                  
      }
    }
  }
  else 
  {   
      do
      {
          while (getchar() != '\n');
          puts("Enter a variable (a to e): ");
      } while (scanf("%c", &var) != 1 || (var != 'a' && var != 'b' && var != 'c' && var != 'd' && var != 'e'));

      n1 = values[var - 'a'];

      op = operatorSelection('U');

      float result = unaryCalculation(n1, op);
      return result;
  }
  return 0;
}