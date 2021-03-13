/*
  @Author: Arshad Shah
  @Date:   Monday, October 19, 2020 10:38 AM
  @Email:  C19485866@mytudublin.ie
  @Filename: lab3_2b.c
  @Last modified by:   Arshad Shah
  @Last modified time: Monday, October 19, 2020 10:38 AM
*/



/* A program to illustrate passing structure values to a function.
	The program reads data for a student and displays it  */

#include <stdio.h>

//global structure template
struct student_rec
{
  int number ;
  char name[26] ;
  int age ;
  int scores[5] ;
};


//Function prototype
void display_student_data(struct student_rec) ;
void get_student_data(struct student_rec *) ;


//main function
void main()
{
  //declare variables
	struct student_rec student ;
	struct student_rec *student_ptr ;

	student_ptr = &student ;

	/* use a pointer to a structure variable as an argument */
	get_student_data( student_ptr ) ;

	/* use a structure variable as an argument */
	display_student_data( student ) ;
  
}//end of main



/* Function: display_student_data() - displays student data
	 Arguments: the student structure                  */
void display_student_data (struct student_rec stud)
{
	int i;
	printf( "\n\nThe data in the student structure is:" ) ;
	printf( "\nnumber is %d" , stud.number ) ;
	printf( "\nname is %s" , stud.name ) ;
	printf( "\nage is %d" , stud.age ) ;
	printf( "\nscores are: " ) ;
	for ( i= 0 ; i < 5 ; i++ )
		 printf( " %d " , stud.scores[i] ) ;
	printf( "\n" ) ;
}//end of function display_student_data


/* Function: get_student_data() - This function reads student data
	Arguments: a pointer to the student structure     */
void get_student_data( struct student_rec *ptr )
{
	int i ;
	printf( "Student Number: " ) ;
	scanf( "%d" , &(ptr->number) ) ;

	printf( "Student Name: " ) ;
	scanf( "%25s" , ptr->name ) ;

	printf( "Age: " ) ;
	scanf( "%d" , &(ptr->age) ) ;

  //take input for test scores
	printf( "5 Test Scores: " ) ;
  //for loop to take input for the test score
	for ( i= 0 ; i < 5 ; i++ )
  {
		scanf( "%d" , &(ptr->scores[i]) ) ;
  }//end of for loop
}//end of function get_student_data
