/*
 * @Author: Arshad shah
 * @Date:   2020-02-19T12:11:16+00:00
 * @Email:  shaharshad1999@outlook.com
 * @Filename: assignement2.c
 * @created using the ATOM editor and Command line GCC compiler
 * @Last modified by:   Arshad shah
 * @Created on        : 2020-02-19
 * @Last modified time: 2020-02-19
 * @Last modified time: 2020-02-20
 * @Last modified time: 2020-02-21
 * @Last modified time: 2020-02-24
 * @Last modified time: 2020-02-25
 * @Last modified time: 2020-02-28
 * @Last modified time: 2020-03-01
 * @Last modified time: 2020-03-02
 * @Last modified time: 2020-03-03
 * @Last modified time: 2020-03-04
 * @Last modified time: 2020-03-05
 * @Last modified time: 2020-03-06
 * @Last modified time: 2020-03-07
 * @Last modified time: 2020-03-08
 * @Last modified time: 2020-03-08
 * @Last modified time: 2020-03-10
 * @Last modified time: 2020-03-11
 */


/*
*This program simulates the lottory game
*where the user chooses 6 numbers for there ticket
*then they check there ticket for winning numbers
*to determine if they have won any price or not
*prices are then shown as per amount of numbers matched to the winning numbers
*the user can also sort there numbers Ascending order
*and check for the frequency of numbers they picked for there ticket
*throughout the games no matter the amount of rounds a user plays
*/

//header files
#include <stdio.h>//standard input output
#include <stdlib.h>//standard library for qsort function
#include <windows.h>//for using of the sleep function


//symbolic names
#define TICKET 6//ticket number size
#define LOTTO 43//lotto game numbers for frequency


//function signatures
void menu();//menu function for displaying menu
void menu_option();//option input funcion to select menu option
int selection(int);//selection function for selecting the menu option1
int option_1(int*, int*);//lotto number input in program|option 1
void option_2(int*);//displays the numbers entered in option1|option 2
int option_3(const void *, const void *);//sorting function (Ascending)|option 3
void option_4(int*);//comparing function|option 4
void option_5(int*,int*);//Frequency function for each number in the ticket| option 5
void repeat_menu();//for repeating the output of menu and and option selection
void menu_error();//for menu error if option 1 is not selected


//start of main function
int main()
{

  //clear screen
  system("cls");
  //call menu function to display the menu for the first time
  menu();

  // call the option input function to get input for the menu option
  menu_option();

  return 0;

}
//end of main function


/*
  This function prints out the main menu of the program
*/
void menu()
{

  //layout design of the menu
  printf("\n\t---------------------------------\n");
  printf("\t--------------Welcome------------\n");
  printf("\t----------------TO---------------\n");
  printf("\t--------------LOTTO--------------\n");
  printf("\t---------------------------------\n");
  printf("\t-------------MAIN MENU-----------\n");
  printf("\t1:- Enter Your Numbers (1 to 42)\n");//option 1
  printf("\t2:- Check the Numbers you entered\n");//option 2
  printf("\t3:- Sort your Numbers (Ascending)\n");//option 3
  printf("\t4:- Check LOTTO outcome\n");//option 4
  printf("\t5:- Frequency of numbers used (1 to 42)\n");//option 5
  printf("\t6:- EXIT Program\n");//option 6
  printf("\t----------------------------------\n");

}//End of menu design function


/*this function takes input for the option selection for the menu
*/
void menu_option()
{

  //variables
  int menu_option;

  //request input for the options from the menu
  printf("\tPlease Enter menu option (1 - 6):");
  scanf("%d",&menu_option);

  //clear screen
  system("cls");

  //error check for character input
  while (getchar() != '\n');

  //send value to selection function to determine the option selected
  selection(menu_option);

}
//end of option selection function


/*This function acts as a selection medium for the menu
*/
int selection(int select)
{

  //variables
  register int i = 0;
  static int numbers[TICKET] = {0};//ticket numbers array to be used as a ticket
  static int Increment_table[LOTTO] = {0};//the allowed x array for the ticket
  static int unlock = 0;


  //switch statement to select the option from the MENU
  switch (select)
  {
    //option 1
    case 1:
    {

      //call the lotto number input function
      unlock = option_1(numbers,Increment_table);

      //display the menu and request option selection from user
      repeat_menu();

      break;
    }//end of case 10


    //option 2
    case 2:
    {
      //clear screen
      system("cls");

      //error check to determine if the user has access
        if (unlock == 1)
        {
          //call option_2 function for output of the array
          option_2(numbers);

          //display the menu and request option selection from user
          repeat_menu();
        }
        else
        {
          menu_error();
        }//end of if else

      break;
    }//end of case 2
    //option 2


    //option 3
    case 3:
    {
      //clear screen
      system("cls");

      //if else to check if other options are unlocked
      if (unlock == 1)
      {
        //qsort from the standard library
        //it uses polymorphic sorting
        //by starting from both start and end of the array
        qsort(numbers, TICKET, sizeof(int), option_3);

        //call sort function to display the sorted array
        option_3(numbers,(numbers+TICKET)-1);

        //output the sorted array
        printf("\n");
        printf("\tSorting");
        Sleep(400);

          //visual affects
          for (i = 0; i < 15; i++)
          {
            printf(".");
            Sleep(60);
          }//end of for loop

        printf("\n\tSorting Successfull\n");
        printf("\tSORTED LIST (ASCENDING)\n");

          //for loop to output array numbers
          for (i = 0; i < TICKET; i++)
          {

            printf("\t%d", *(numbers+i) );

          }//end of for loop for output of sorted list

        //display the menu and request option selection from user
        repeat_menu();
      }//end of if
      else
      {
        //call menu error function
        menu_error();

      }//end of else

      break;
    }
    //end of case 3


    //option 4
    case 4:
    {
      //clear screen
      system("cls");

        //if else to check if other options are unlocked
        if (unlock == 1)
        {
          //wining numbers 1,3,5,7,9,11
          //call the number comparing function
          option_4(numbers);

          //display the menu and request option selection from user
          repeat_menu();
        }//end of if
        else
        {
          //call menu error function
          menu_error();

        }//end of else

      break;
    }
    //end of option 4


    //option 5
    case 5:
    {
      //clear screen
      system("cls");

        //if else to check if other options are unlocked
        if (unlock == 1)
        {

          //call the frequency function
          option_5(numbers,Increment_table);

          //display the menu and request option selection from user
          repeat_menu();

        }//end of if
        else
        {
          //call menu error function
          menu_error();

        }//end of else

      break;
    }
    //end of case 5 for option 5 in program


    //option 6
    case 6:
    {
      //variables
      char exit_confirm;

      //to ask question for confirmation
      printf("\tAre you sure you want to exit the game?(y or n)\n");
      scanf("%s",&exit_confirm );

      //switch statement for confirmation message
      switch (exit_confirm)
      {
        case 'y':
        case 'Y':
          {
            //exit string 1
            printf("\tThank you for playing\n");
            printf("\tDesigned and created by : ARSHAD SHAH\n");
            printf("\tUsing the GCC compiler and ATOM editor\n");

            //output a string for the exit of the program
            char terminate_string[] = "Exiting Program";

            //print out the exit string 2
            printf("%s", terminate_string );

              //visual effects
              for (i = 0; i < 30; i++) // i < |30| is the number of dots
              {
                printf(".");
                Sleep(20);//wait between each dot printout
              }
            //wait for visual affects
            Sleep(100);
            exit(0);//exit function to gracefully exit the program

            break;
          }
          //end of case Yes

          //case no for not closing program
          case  'n':
          case  'N':
          {
            //clear screen
            system("cls");
            //call menu and option function for repeating the program
            repeat_menu();
            break;
          }
          //end of case no

      }//end of switch statement for exiting program confirmation


      break;
    }
    //end of case 6 for exit


    //default for error correction
    default:
    {
      //print the error message
      printf("\tInvalid input!!!!!\n");
      printf("\tPlease Try again\n");

      //display the menu and request option selection from user
      repeat_menu();

      break;
    }//end of default

  }//end of switch
}//end of option selection


/*
  this function requests input of the lottory numbers and printf them in an array
*/
int option_1(int *numbers ,int *Increment_table)
{
  //variables
  register int i , j;
  int input;


  printf("\tEnter your ticket numbers (1 - 42) Inclusive\n");

  //Request input for 6 numbers using a for loop for data input
    for (i = 0; i < TICKET; i++)
    {
      //request input for the ticket numbers
      printf("\tEnter number %d: ",i+1);
      scanf("%d",&input);

        for( j = 0; j < i; j++)
        {
            //error correction by creating a range for ticket array and
            //checking the inprintf with that array range
             if ((input < 1 || input > 42)) //Error checking
             {

               printf("\tInvalid input!!!!! (ONLY 1 TO 42 ARE ALLOWED)\n");
               printf("\tPlease try again\n");
               printf("\tEnter number %d: ",i+1);
               scanf("%d", &input);

               //error checking for characters
               while (getchar() != '\n');
               j = 0;

             }//end of if
             else if (input == *(numbers+j))
             {

               printf("\tDuplicate numbers are not allowed\n");
               printf("\tPlease try again\n");
               printf("\tEnter number %d: ",i+1);
               scanf("%d", &input);

               //error checking for characters
               while (getchar() != '\n');
               j = 0;

             }
        }//end of inner for loop

        *(numbers + i) = input;

        //frequency checker
        *(Increment_table + *(numbers + i)) = *(Increment_table + *(numbers + i)) + 1;

    }//end of the outer for loop

    //clear screen
    system("cls");

    //return 1 to unlock other options
    return 1;
}//end of number input function option_1()


/*
This function prints out the numbers entered in the first option
*/
void option_2(int *numbers)
{
  //variables
  register int i;

  printf("\n");
  printf("\tThe numbers you entered are:\n");

   //for loop to read from the array
   for (i = 0; i < TICKET; i++)
   {

     printf("\t%d", *(numbers + i) );

   }//end of for loop for array elements output

}
//end of function for array print


/*
 This function sorts the array in Ascending order using built in function in c
*/
int option_3(const void * a, const void * b)
{

  return ( *(int*)a - *(int*)b );//a = element 0 and b = last element.

}
//end of sorting algorithm


/*
  This function compares the winning numbers with the numbers enetered by
  the user
*/
void option_4(int *numbers)
{
  //variables
  int winning_numbers[TICKET] = {1,3,5,7,9,11};
  int match = 0;
  register int i,j;

  //display the numbers that the user entered
  option_2(numbers);

  //print the winning numbers
  printf("\n");
  printf("\n\tThe winning numbers:\n");

  //for loop to compare the numbers in the two arrays
  for ( i = 0; i < TICKET; i++)
  {
    //print the winning numbers
    printf("\t%d  ",*(winning_numbers+i) );

      for (j = 0; j < TICKET; j++)
      {

        //if statement to check each element of the array
        if (*(winning_numbers+i) == *(numbers+j))
        {

          //number counter for comparing arrays
          match++;

        }//end of if else for comparing of the arrays.

      }//end of inner for loop
  }//end of outer for loop

  //switch statement to check for other combination
  //of the lotto number match
  switch (match)
  {
    //case 6 for 6 numbers
    case 6:
    {
      printf("\n");
      printf("\tCONGRATULATIONS YOU HAVE WON THE JACKPOT\n");
      break;
    }
    //end of case 6 for comparing 6 numbers


    //case5 for 5 numbers
    case 5:
    {
      printf("\n");
      printf("\tCONGRATULATIONS YOU HAVE WON A CAR\n");
      break;
    }
    //end of case 5 for comparing of 5 numbers

    //case4 for 4 numbers
    case 4:
    {
      printf("\n");
      printf("\tCONGRATULATIONS YOU HAVE WON A WEEKEND AWAY TO HAWAII\n");
      break;
    }
    //end of case 4 for 4 numbers


    //case 3 for 3 numbers
    case 3:
    {
      printf("\n");
      printf("\tCONGRATULATIONS YOU HAVE WON A CINEMA PASS\n");
      break;
    }
    //end of case 3 for 3 numbers


    //case 2 for 2 numbers
    case 2:
    {
      printf("\n");
      printf("\tONLY TWO NUMBERS MATCH.\n");
      printf("\tGOOD LUCK NEXT TIME\n");
      break;
    }
    //end of case 2 for 2 numbers


    //case 1 for 1 numbers
    case 1:
    {
      printf("\n");
      printf("\tONLY ONE NUMBERS MATCH.\n");
      printf("\tGOOD LUCK NEXT TIME\n");
      break;
    }
    //end of case 1 for 1 numbers


    //default case
    default:
    {
      printf("\n");
      printf("\tSORRY YOU DID NOT WIN A PRIZE\n");
      printf("\tGOOD LUCK NEXT TIME!!\n");
      printf("\n");
      break;
    }//end of default

  }//end of switch statement for number comparing
}
//end of number comparing function


/*
  This function finds the frequency of the numbers entered by the users
  through out the game
*/
void option_5(int *numbers , int *Increment_table)
{

  //variables
  register int i;

  /* Print frequency of each element in the array numbers */
  printf("\n\tThe Frequency of numbers in Ticket\n");

  //for loop to access the array Increment_table
  for(i=0; i<LOTTO; i++)
  {
    if (*(Increment_table+i) != 0)
    {
      printf("\n");
      printf("\tThe number %d is selected %d times\n",i,*(Increment_table+i));
    }
  }//end of for loop

}
//end of frequency function

/*
  This function redo the output of menu and requests option selection
  after every menu option is completed
*/
void repeat_menu()
{

  //print shorter menu
  printf("\n\t-------------MAIN MENU-----------\n");
  printf("\t1:- Enter Your Numbers (1 to 42)\n");//option 1
  printf("\t2:- Check the Numbers you entered\n");//option 2
  printf("\t3:- Sort your Numbers (Ascending)\n");//option 3
  printf("\t4:- Check LOTTO outcome\n");//option 4
  printf("\t5:- Frequency of numbers in ticket\n");//option 5
  printf("\t6:- EXIT Program\n");//option 6
  printf("\t----------------------------------\n");

  // call the option input function
  menu_option();

}
//end of repeat function


/*
  This function outprintf a warning in case anything other than option 1 is
  selected
*/
void menu_error()
{
  //clear screen
  system("cls");

  //print warning
  printf("Sorry option 1 must be selected to access other options\n");

  //call menu repeat function
  repeat_menu();
}
//end of error correction
