/*
*This is a calculator program
*/

/*
*Author: Arshad shah
*Created on: 10 october 2019.
*/

#include <stdio.h>

int main()
{
    //variables declared
    char operate;
    int num1;
    int num2;
    int answer;
    char calcType;
    _Bool operater;
    _Bool reDo;

//start of do while loop
do {
  //layout and calculation type
  printf("Please choose calculation type you would like to "
        " perform (Mathmatical=M, Boolean= B, Relational=R:" );
  scanf("%c", &calcType);

  switch (calcType)
  {
    case 'M':
    case 'm':
    {
      printf("---------------mathematical calculation-------------\n" );
      //mathematical calculation
      //request input for first number
      printf("Please input first number: ");
      scanf("%d",&num1);

      //input of second number
      printf("Please input second number: ");
      scanf("%d",&num2 );

      //operater input
      printf("Please input an operater from the following (+,-,*,/,%): ");
      scanf("%1s",&operate );

      //switch statement for operater
      switch (operate)
      {
        case '+':
        {
          answer = num1 + num2;
          printf("Your addition is: %d\n", answer);
          break;
        }
        case '-':
        {
          answer = num1 - num2;
          printf("Your subtraction is: %d\n", answer);
          break;
        }
        case '*':
        {
          answer = num1 * num2;
          printf("Your Multiplication is: %d\n", answer);
          break;
        }
        case '/':
        {
          answer = num1 / num2;
          printf("Your division is: %d\n", answer );
          break;
        }
        case '%':
        {
          answer = num1 % num2;
          printf("Your modulus is: %d\n", answer );
          break;
        }

        default:
        {
          printf("you entered a bad value!\n");
        }
      }//end of switch
      break;
    }//end of case mathematics

    case 'B':
    case 'b':
    {
        printf("---------------Boolean calculation-------------\n" );
      //mathematical calculation
      //request input for first number
      printf("Please input first number: ");
      scanf("%d",&num1);

      //input of second number
      printf("Please input second number: ");
      scanf("%d",&num2 );

      //operater input
      printf("Please input an operater from the following (>,<,=): ");
      scanf("%1s",&operater );

      //switch statement for operater
      switch (operate)
      {
        case '>':
        {
          answer = num1 > num2;
          printf("Your answer is: %d\n", answer);
          break;
        }
        case '<':
        {
          answer = num1 < num2;
          printf("Your answer is: %d\n", answer);
          break;
        }
        case '=':
        {
          answer = num1 = num2;
          printf("Your answer is: %d\n", answer);
          break;
        }
        default:
        {
          printf("you entered a bad value!");
        }
      }//operater for Boolean
    }//boolean calculation
  }//end of switch calculation type

  printf("Do you want to perform another calculation (Y or N):\n");
  scanf("%1s", &reDo );
} while(reDo = 'Y');
//end of do while


  getchar();
  getchar();
  return 0;
}
