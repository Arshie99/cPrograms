/*
This is a program for a 5 question quiz.
*/

/*
Created by: Arshad shah
Date: 25 october 2019 at 11:50
modified 28 october 2019 at 12:30
modified at 30 october 2019 at 3:00
modified at 3 november 2019 at 9:00
modified at 5 november 2019 at 6:00
modified at 8 november 2019 at 5:00
modified at 10 november 2019 at 10:46
*/

#include <stdio.h>
#include <stdlib.h>

// start of main
int main()
{

  //variables declared and initialized
  int menu;
  int question;
  int i;
  int input = 0;
  int random = 0;
  //counter
  int counter_correct = 0;
  int counter_incorrect = 0;

  //A do while loop to repeat the program as long as option 4 is not selected
  do
  {

    //menu layout and option input
    //layout of the menu
    printf(" ------------------QUIZ--------------------\n\n");
    printf(" ------------------MENU--------------------\n");
    printf(" 1 ==> Number of Questions\n");
    printf(" 2 ==> Start the Quiz\n");
    printf(" 3 ==> Results\n");
    printf(" 4 ==> Exit program\n");
    printf(" Your Selected option: ");
    scanf("%d",&menu );

    //end of menu option and layout input

    //error checker
    if(menu < 1 || menu > 4)
    {
      printf("\n Invalid entry!!!!!\n");
      printf(" Try Again!!!!!\n");
    }

    //else statement for initial error checking
    else
    {
      //menu actions
      switch (menu)
      {
        case 1:
        {
          //menu option 1

          //do while for error checking
          do
          {
            counter_correct = 0;
            counter_incorrect = 0;
            printf(" How many questions would you like to attempt (max 5): ");
            scanf("%d\n",&question );

            if (question < 1 || question > 5)
            {
              printf(" Invalid entry!!!!!\n");
              printf(" Try Again!!!!!\n");
            }
          }while(question < 1 || question > 5);
          //end of do while for error checking
          break;
        }
        //case 1 for option 1

        //case 2 option 2
        case 2:
        {
        //menu option 2
          if (question < 1 || question > 5 && menu > 1)
          {
            printf(" Sorry you need to start from the beginning.\n");
          }

          else
          {
            
            printf("\n The quiz is starting..............\n");

            //for loop for questions
            for(i = 0; i < question; i++)
            {
              random = rand() % 100 + 1;

              printf("\n What is 1 x %d ? ", i + random);
              scanf("%d", &input);

              //if statement for question check output message
              if(input ==  random + i)
              {
                printf(" %d is the correct answer!\n", input) ;
                counter_correct++;
              }

              else
              {
                printf(" You entered incorrect! Answer is: %d\n", (random + i)) ;
                counter_incorrect++;
              }
            }//end of for loop
          }//if else statement
          break;
        }//end of case 2


        //case 3 option 3
        case 3:
        {
          //menu option 3
          //error checking for option 3
          if (question < 1 || question > 5 && menu > 1 )
          {
            printf(" Sorry you need to start from the beginning.\n");
          }

          else
          {
            printf(" Here is your result: %d correct , %d Incorrect \n", counter_correct,counter_incorrect );
          }

          break;
        }
        //end of case3


        //case 4 for option 4
        case 4:
        {
          printf(" Exiting program...................\n");
          exit(0);
          //exit statement

          break;
        }
        //end of case 4

        //default statement
        default:
        {
          printf(" Your input is invalid!!!!!\n");
          printf(" Please Try again!!!!!!\n");
          break;
        }
        //end of default statement

      }//end of switch statement for menu option selection

    }//menu error checking

  }while( menu > 0 || menu < 4 );//end of do while

  return 0;
}
//end of main
