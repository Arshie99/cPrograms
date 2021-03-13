/*
  @Author: Arshad Shah
  @Date:   Monday, October 19, 2020 10:56 AM
  @Email:  C19485866@mytudublin.ie
  @Filename: lab4.c
  @Last modified by:   Arshad Shah
  @Last modified time: Monday, October 19, 2020 10:56 AM
*/


//header files
#include <stdio.h>

//structures
struct block
{
  int proc_id;
  int proc_stat;
  int count;
  int accum;
  int que;
  char account[];
};

//function prototypes
void create_node(struct block *);
void display_node(struct block);


//main
int main()
{
  //declare variables
	struct block number1 ;
	struct block *number1_ptr ;

	number1_ptr = &number1 ;

	/* use a pointer to a structure variable as an argument */
	create_node( number1_ptr ) ;

	/* use a structure variable as an argument */
	display_node( number1 ) ;
}//end of main


/*
  This function creates the structure for block and populates it with data
*/
void create_node( struct block *ptr )
{

	printf( "Process ID: " ) ;
	scanf( "%d" , &(ptr->proc_id) ) ;

	printf( "Process status: " ) ;
	scanf( "%d" , (ptr->proc_stat) ) ;

	printf( "Counter: " ) ;
	scanf( "%d" , &(ptr->count) ) ;

  printf( "Accumulator: " ) ;
	scanf( "%d" , &(ptr->accum) ) ;

  printf( "Queue: " ) ;
	scanf( "%d" , &(ptr->que) ) ;

  printf( "Account: " ) ;
	scanf( "%s" , &(ptr->account) ) ;

}//end of function get_student_data


/*
  This function displays the structure for block
*/
void display_node( struct block nodes )
{

	printf( "\n\nThe data in the block structure is:" ) ;

  printf( "Process ID: ", nodes.proc_id ) ;

	printf( "Process status: ", nodes.proc_stat ) ;

	printf( "Counter: " , nodes.count) ;

  printf( "Accumulator: ", nodes.accum) ;

  printf( "Queue: ", nodes.que ) ;

  printf( "Account: ", nodes.account ) ;

}//end of function get_student_data
