/**
 * @Author: Arshad shah
 * @Date:   2020-04-03T11:52:49+01:00
 * @Email:  shaharshad1999@outlook.com
 * @Filename: exam.c
 * @Last modified by:   Arshad shah
 * @Last modified time: 2020-04-03T11:52:53+01:00
 */

/*
*This program takes a four digit code as input.
*encrypt the code using an encrption algorithm,
*compare the code with the authorised code,
*decrypt the code
*show the amount of time the code was correct and incorrect
*it also requests confirmation upon exit to ensure a clean and gracefull exit
*/


//header files
#include <stdio.h>//standard input output
#include <stdlib.h>//standard library
#include <windows.h>//for the sleep function
#include <string.h>//for use in strings
#include <time.h>//for random number generator


//symbolic names
#define CODE 4


//structure template
struct code_counter
{

  int correct_code;
  int wrong_code;

}counter;

//function signatures
void main_menu();//to print out the main menu
void repeat_menu();//to print a scaled down version of main menu on repeat
void error();//to print error and repeat the menu
int menu_option();//to take menu option input
void menu_selector(int);//select menu option based on the input in menu_option
int option_1(int*);//Takes in 4 integer input | option1
int option_2(int*);//encrypts the code entered in option 1
void swap(int*);//swap the elements in the array
void option_3(int*);//to compare the access code with the entered code or generated code
void option_4(int *);//to decrypt the entered code
void option_5();//display the correct and incorrect values stored in structure



//start of main
int main()
{

  //clear screen
  system("cls");

  //print out the menu
  main_menu();

  //request option selection
  menu_option();
  return 0;

}
//end of main


/*
  This function prints out the main menu when the program is run
*/
void main_menu()
{

  printf("\t___________________________________________________________\n");
  printf("\t--------------------Encryption Program---------------------\n");
  printf("\t-----------------------Main Menu---------------------------\n");
  printf("\t___________________________________________________________\n");
  printf("\t1=> Enter a 4 Digit Numeric code___________________________\n");
  printf("\t2=> Encrypt your code______________________________________\n");
  printf("\t3=> Compare code to autorized code_________________________\n");
  printf("\t4=> Decrypt your code______________________________________\n");
  printf("\t5=> Show the frequency of correct and incorrect entry______\n");
  printf("\t6=> Exit program___________________________________________\n");
  printf("\t___________________________________________________________\n");

}//end of menu function


/*
  This function prints a scaled down version of the main menu on repeat
*/
void repeat_menu()
{

  //print shorter menu
  printf("\t___________________________________________________________\n");
  printf("\t-----------------------Main Menu---------------------------\n");
  printf("\t___________________________________________________________\n");
  printf("\t1=> Enter a 4 Digit Numeric code___________________________\n");
  printf("\t2=> Encrypt your code______________________________________\n");
  printf("\t3=> Compare code to autorized code_________________________\n");
  printf("\t4=> Decrypt your code______________________________________\n");
  printf("\t5=> Show the frequency of correct and incorrect entries____\n");
  printf("\t6=> Exit program___________________________________________\n");
  printf("\t___________________________________________________________\n");

  //request menu option input
  menu_option();

}//end of repeat menu function


/*
  This function outprintf a warning in case anything other than option 1 is
  selected
*/
void error()
{
  //clear screen
  system("cls");

  //print warning
  printf("Sorry the pin must be entered  or generated to access other options\n");

  //wait
  Sleep(100);

  //call menu repeat function
  repeat_menu();
}
//end of error correction


/*
  This function requests input for the menu
*/
int menu_option()
{
  //declare variables
  int option = 0;//input
  int temp;//temporary variable to catch rubbish characters
  int status;//status variable to store status of input

  //request menu option input
  printf("\tPlease enter menu option (1 <--> 6):");
  status = scanf("%d", &option );

    //character error check
    while(status!=1)
    {
      //while loop to collect characters and remove it
      while((temp=getchar()) != EOF && temp != '\n');

      //print message
      printf("\tInvalid input...\n");
      printf("\tplease enter a number\n");
      printf("\tPlease enter menu option (1 <--> 6):");

      //take input
      status = scanf("%d", &option);

    }//end of while loop


    //error correction by creating a range for ticket array and
    //checking the printf with that array range
     if ((option < 1 || option > 6)) //Error checking
     {

       printf("\tInvalid input!!!!! (ONLY 1 TO 6 ARE ALLOWED)\n");
       printf("\tPlease try again\n");
       printf("\tPlease enter menu option (1 <--> 6):");
       status = scanf("%d", &option);


       //character error check
       while(status!=1)
       {
         //while loop to collect characters and remove it
         while((temp=getchar()) != EOF && temp != '\n');

         //print message
         printf("\tInvalid input...\n");
         printf("\tplease enter a number\n");
         printf("\tPlease enter menu option (1 <--> 6):");

         //take input
         status = scanf("%d", &option);

       }//end of while loop

     }//end of if

  //send value to menu selector
  menu_selector(option);

}//end of menu option selection function


/*
  This function selects a menu option based on menu_option function
*/
void menu_selector(int select)
{
  //declare variables
  register int i;//for loop counter
  static int code[CODE] = {0};//the input pin array
  static int input_unlock = 0;//unlock option 2 if data is entered in option 1
  static int encryption_unlock = 0;//unlock option 3 and 4 if the data is encrypted
  static int lock = 0;//lock the encryption function if it has already encrypted


  //switch statement to select the correct menu option
  switch (select)
  {
    case 1:
    {
      //increment value of lock to differentiate between states
      lock = 0;

      //call the number input function
      input_unlock = option_1(code);

      //display the menu and request option selection from user
      repeat_menu();

      break;
    }//end of case 1 option 1

    case 2:
    {
      //clear screen
      system("cls");

      //check if user has access to other options
        if (lock == 1)
        {
          printf("\tAlready Encrypted\n");

          //display the menu and request option selection from user
          repeat_menu();
        }
        else if (input_unlock == 1)
        {

          //call option_2 function to encrypt the array code
          encryption_unlock = option_2(code);

          //increment value of lock to differentiate between states
          lock = 1;

          //display the menu and request option selection from user
          repeat_menu();
        }
        else
        {

          //dislay error message and repeat menu
          error();

        }//end of if else

      break;
    }//end of case 2 option 2

    case 3:
    {
      //clear screen
      system("cls");

      //check if user has access to other options
        if (encryption_unlock == 1)
        {

          //call option_3 function for comparing of the arrays
          option_3(code);

          //display the menu and request option selection from user
          repeat_menu();

        }
        else
        {

          //clear screen
          system("cls");

          //print warning
          printf("Sorry you must encrypt your code to access this options\n");

          //wait
          Sleep(200);

          //call menu repeat function
          repeat_menu();

        }//end of if else

      break;
    }//end of case 3 option 3

    case 4:
    {
      //clear screen
      system("cls");

      //check if user has access to other options
        if (encryption_unlock == 1)
        {

          //call option_4 to decrypt the encrypted code
          option_4(code);

          //display the menu and request option selection from user
          repeat_menu();

        }
        else
        {

          //clear screen
          system("cls");

          //print warning
          printf("Sorry you must encrypt your code to access this options\n");

          //wait
          Sleep(200);

          //call menu repeat function
          repeat_menu();

        }//end of if else
      break;
    }//end of case 4 option 4

    case 5:
    {

      //clear screen
      system("cls");

      //call option_5 to show the correct and incorrect counters
      option_5();

      //display the menu and request option selection from user
      repeat_menu();

      break;
    }//end of case 5 option 5

    case 6:
    {

      //variables
      char exit_confirm;

      //to ask question for confirmation
      printf("\t___________________________________________________________\n");
      printf("\tAre you sure you want to exit?\n");
      printf("\tYES => y | NO => n\n");
      printf("\t=> ");
      scanf("%1s",&exit_confirm );

      //switch statement for confirmation message
      switch (exit_confirm)
      {

        case 'y':
        case 'Y':
          {
            //clear screen
            system("cls");
            //exit string 1
            printf("\tDesigned and created by : ARSHAD SHAH\n");
            printf("\tUsing the GCC compiler and ATOM editor\n");
            printf("\t___________________________________________________________\n");

            //output a string for the exit of the program
            char terminate_string[] = "Exiting Program";

            //print out the exit string 2
            printf("\t%s", terminate_string );

              //visual effects
              for (i = 0; i < 40; i++) // i < |40| is the number of dots
              {

                printf(".");
                Sleep(15);//wait between each dot printout

              }//end of for loop for visual affects

            //wait for visual affects
            Sleep(90);
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

          //default case for error checking
          default:
          {

            //clear screen
            system("cls");

            //print error message
            printf("\tInvalid input!!!!!!\n");
            printf("\tPlease try again\n");

            //wait
            Sleep(200);

            //clear screen
            system("cls");

            //call menu and option function for repeating the program
            repeat_menu();

            break;
          }

      }//end of switch statement for exiting program confirmation

      break;
    }//end of case 6 option 6

  }//end of menu selection switch statement

}//end of menu selector function


/*
  This function takes input of 4 digit code for option 1 in the menu
*/
int option_1(int *code)
{
  //variables
  register int i , j;//for loop counters
  int input;//user input
  char option_confirm;//for random or manual entry confirmation
  int temp;//for collecting characters
  int status;//status to determine if the user has entered a number or letter


  //clear screen
  system("cls");

  //request if the user want to randomly create a code
  //or manually enter it
  printf("\n\tDo you want to create a random code\n");
  printf("\t\tOR\n");
  printf("\tDo you want to manually enter it.\n");
  printf("\tEnter R for random | Enter M for manual : ");

  //confirmation input scanf
  scanf("%1s",&option_confirm );

  //switch statement for pin input or random generation
  switch (option_confirm)
  {

    case 'm':
    case 'M':
    {

      //clear screen
      system("cls");
      //request input for 4 integers
      printf("\tEnter your 4 Digit pin number\n");

      //Request input for 4 numbers using a for loop for data input
      for (i = 0; i < CODE; i++)
      {
        //request input for the code
        printf("\tEnter number %d: ",i+1);
        status = scanf("%d",&input);

          //character error check
          while(status!=1)
          {
            //while loop to collect characters and remove it
            while((temp=getchar()) != EOF && temp != '\n');

            //print message
            printf("\tInvalid input...\n");
            printf("\tplease enter a number\n");
            printf("\tEnter number %d: ",i+1);

            //take input
            status = scanf("%d", &input);

          }//end of while loop

        //inner for loop
        for( j = 0; j < CODE; j++)
        {
          //error correction by creating a range for pin array and
          //checking the scanf with that array range
           if ((input < 0 || input > 9)) //Error checking
           {

             printf("\tInvalid input!!!!! (ONLY 0 TO 9 ARE ALLOWED)\n");
             printf("\tPlease try again\n");
             printf("\tEnter number %d: ",i+1);
             status = scanf("%d", &input);


             //character error check
             while(status!=1)
             {
               //while loop to collect characters and remove it
               while((temp=getchar()) != EOF && temp != '\n');

               //print message
               printf("\tInvalid input...\n");
               printf("\tplease enter a number\n");
               printf("\tEnter number %d: ",i+1);

               //take input
               status = scanf("%d", &input);

             }//end of while loop
             j = 0;

           }//end of if

        }//end of inner for loop

        //assign the values to the array
        *(code + i) = input;

      }//end of the outer for loop

      //clear screen
      system("cls");
      break;
    }//end of case manual

    //switch case for random code creation
    case 'R':
    case 'r':
    {
      //clear screen
      system("cls");

      //initialize variables
       time_t t;

       /* Intializes random number generator */
       srand((unsigned) time(&t));

         /* Print 4 random numbers from 0 to 9 */
         for( i = 0 ; i < CODE ; i++ )
         {
            //random number generator
            *(code + i ) = rand() % 10;
         }//end of for loop to generate numbers between 0 to 9 for each element
          //in array

        break;
      }//end of case random


    //default case
    default:
    {

      //print error message
      printf("\tIncorrect option selected\n");
      printf("\tPlease try again!!!\n");
      //wait
      Sleep(1000);

      //call option 1
      option_1(code);
    }//end default case

  }//end of switch statement for input option confirmation

  //return 1 to unlock other options
  return 1;
}//end of option 1 number input function


/*
  This function encrypts the code using a set of predefined method
*/
int option_2(int *code)
{
  //initialize and declare variables
  register int i;

    //print out of the Plain text
    printf("\tPlain code:");

    //for loop to print the array
    for (i = 0; i < CODE; i++)
    {

      printf("%d ",*(code+i) );

    }//end of for loop for print out of code before Encryption

  //padding
  printf("\n");

  //call swapping function
  swap(code);

  //add one to all elements in the array
  for (i = 0; i < CODE; i++)
  {

    //check if element is in the range of 0 t0 9 inclusive
    //add 1 to it
    if(*(code+i) <= 9 && *(code+i) >= 0)
     {
         *(code + i) = *(code + i) + 1;//add 1

         //if code is > 9
         if(*(code+i) > 9)
         {
           *(code + i) = 0;//change to 0
         }//end of inner if for greater than 9 check

     }//end of outer if for less than 9 and greater than 1 check

  }//end of for loop for adding 1 to the code


    //print out of the Encrypted code
    printf("\tEncrypted code:");

    //for loop to print the array
    for (i = 0; i < CODE; i++)
    {

      printf("%d ",*(code+i) );

    }//end of for loop for print out of code after encryption

  //padding
  printf("\n");

  //return 1 to unlock other options
  return 1;
}//end of menu option 2 for encryption of code


/*
  This function does the swapping of elemnts for the encryption in option 2
*/
void swap(int *code)
{
  //swap the first element with  the third element in the array
  int swap = *code;
  *code = *(code + 2);
  *(code + 2) = swap;

  //swap the second element with the fourth element in the array
  swap = *(code + 1);
  *(code+1) = *(code + 3);
  *(code + 3) = swap;
}//end of swapping function for encryption


/*
  This function compares the encrypted code to the access code and displays
  correct input or wrong input messages
*/
void option_3(int *code)
{
  //initialize and declare variables
  const int access_code[CODE] = {4,5,2,3};//access code for comparison
  register int i , j;//for loop counters
  int match = 0;//array comparison counter
  //correct incorrect counter
  static int correct = 0;
  static int incorrect = 0;

    //message print
    printf("\tEncrypted Code:");
    //for loop to display the encrypted numbers
    for (i = 0; i < CODE; i++)
    {

      //print encrypted code
      printf("%d ",*(code+i) );

    }//end of for loop

    //print access code
    printf("\n\tAccess code:");
    //check if the entered code is the same as access code
    for (i = 0; i < CODE; i++)
    {
      //print access code
      printf("%d ",*(access_code+i) );

        //if statemnt to compare arrays and increment counter
        //if same element is found
        if (*(code + i) == *(access_code + i))
        {

          match++;//increment counter

        }//end of if statement for counter

    }//end of outer for loop

  //if statement to display message
  if (match == CODE)
  {

    printf("\n\tCorrect Code entered\n");
    correct++;

  }
  else
  {

    printf("\n\tWrong Code entered\n");
    incorrect++;

  }//end of if else for message printout

  //assign correct and incorrect counter to structure
  counter.correct_code = correct;
  counter.wrong_code = incorrect;

}//end of comparing function


/*
  This function decrypts the encrypted code and prints it
*/
void option_4(int *code)
{
  //initialize and declare variables
  register int i;

    //print out of the encrypted code
    printf("\tEncrypted code:");

    //for loop to print the array
    for (i = 0; i < CODE; i++)
    {
      printf("%d ",*(code+i) );
    }//end of for loop for print out of code before decryption

  //padding
  printf("\n");


  //add one to all elements in the array
  for (i = 0; i < CODE; i++)
  {
    //check if element is less than or equal to 9 if it is add 1 to it
    if(*(code+i) <= 9 && *(code+i) >= 0)
     {
       *(code + i) = *(code + i) - 1;//take 1 away

         //if stateent to determine if input is > 9
         if(*(code+i) == -1)
         {
           *(code + i) = 9;//chage to 9
         }//end of inner if for greater than 9 check

     }//end of outer if for less than 9 and greater than 1 check

  }//end of for loop for adding 1 to the code

  //call swapping function
  swap(code);


    //print out of the Decrypted code
    printf("\tDecrypted code:");

      //for loop to print the array
      for (i = 0; i < CODE; i++)
      {
        printf("%d ",*(code+i) );
      }//end of for loop for print out of code after decryption

  //padding
  printf("\n");

}//end of decryption function


/*
    This function displays the correct and incorrect counter stored in the
    structure counter
*/
void option_5()
{

  printf("\tCorrect Entries %d\n",counter.correct_code );//correct counter
  printf("\tIncorrect Entries %d\n",counter.wrong_code );//incorrect counter values

}//end of counter displaying function
