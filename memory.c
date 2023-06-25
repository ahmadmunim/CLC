#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "memory.h"
#include "main.h"

static float memory[1000]; // THIS ARRAY WILL BE USED TO STORE ANY CALCULATION

void memoryView() // SHOWS THE USER THE VALUES THAT ARE STORED IN THE MEMORY
{

    int selection;

    if (counter == 0)
      puts("Currently, there are no items saved in the memory.");

    else 
    {
      printf("The past %d results are stored (maximum is 1000)\n", counter);
      
      do
      {
        while(getchar() != '\n');
        puts("Enter '0' to see all the stored items. Enter a number between 1 and the total number of values stored to see the corresponding value.");
      } while (scanf("%d", &selection) != 1 || (selection > counter)); // CONTINUES ASKING THE USER TO INPUT A NUMBER AS LONG AS THE USER
                                                                       // INPUTS A NUMBER THAT'S GREATER THAN THE NUMBER OF VALUES IN
                                                                       // THE MEMORY
      
      if (selection == 0) // PRINTS ALL THE VALUES STORED IN THE MEMORY ALONG WITH IT'S POSITION
      {
        for (int i = 0; i < counter; i++)
        {
          printf("[%d] %f\n", i+1, memory[i]);
        }      
      }
      
      else
        printf("[%d] %f\n", selection, memory[selection - 1]); // PRINTS THE CORRESPONDING VALUE TO THE POSTION VALUE THE USER INPUTS
    }
}

void memoryStore(float ans) // STORES A CALCULATION IN AN ARRAY WHICH REPRESENTS THE MEMORY OF THE CALCULATOR
{
  counter++; // THIS COUNTER REPRESENTS THE NUMBER OF CALCULATIONS DONE

  if (counter >= 1000) // THIS IS FOR WHEN THERE ARE 1000 ITEMS IN THE MEMORY ARRAY 
  {
    counter = 1000;
    for (int i = 0; i < counter - 1; i++)
    {
      memory[i+1] = memory[i]; // THE FIRST ELEMENT GETS PUSHED OUT THE THE ARRAY AND THE SUCCEEDING ELEMENT'S POSITION SUBTRACTS BY 1     
    }
    memory[counter - 1] = ans;
  }
  else
    memory[counter - 1] = ans; // STORES THE CALCULATION IN THE ARRAY
}

void memoryClear() // CLEARS MEMORY WHEN THE USER ENTERS 'R' AS AN OPTION
{
  counter = 0; // THE COUNTER ALSO RESETS TO 0 SINCE A MEMORY RESET WOULD MEAN THAT THERE ARE NO CALCULATED VALUES IN THE MEMORY ARRAY
  for (int i = 0; i < 1000; i++) // RESETS THE MEMORY ARRAY BY MAKING ALL THE VALUES IN IT TO 0
    memory[i] = 0;
  puts("Memory cleared!");
}