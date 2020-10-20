/*This program generates random numbers and compares it to number input
from user*/

/*
Created by: Arshad shah
Date: Tuesday 22 october 2019 at 9:35 AM
*/


#include <stdio.h>
#include <stdlib.h> // this header file is required for the rand() function

int main()
{
  int num = 0;
  int input = 0;


  for (int i = 1; i <= 5; i++)
  {
    //request an input for a random number
    printf("\nPlease input a number between 1 - 10: ");
    scanf("%d", &input );

    if (input <= 10 && input >= 1)
    {//start of error check if statement
      
      //generate random number
      printf("Generating a random number between 1 - 10: %d\n" , num);

      // num is assigned a random number between 1 – 10
      num = rand() % 10 + 1;

      //comparing of the two numbers
      if ( input == num )
      {
        printf("Same Numbers: %d" , input);
      }

      else if (input != num)
      {
        printf("Different numbers");
      }

    }//end of error check if statement
    else
    {
      printf("Please try Again!!!\n");
    }
}//end of for statement

  //number tally for same and Different

  //reason for the double get char is due to windows.
   getchar();
   getchar();
   return 0;

} // end main
