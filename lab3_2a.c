/*
  @Author: Arshad Shah
  @Date:   Monday, October 19, 2020 10:33 AM
  @Email:  C19485866@mytudublin.ie
  @Filename: lab3_2a.c
  @Last modified by:   Arshad Shah
  @Last modified time: Monday, October 19, 2020 10:34 AM
*/



/* A program to illustrate using an array of strings.

	The program stores the months of the year in an array and the
	displays them to the user */


#include <stdio.h>
void main()
{
	/* Define an array of strings */
	char *months[12] = {"January", "February", "March", "April", "May", "June",
							  "July", "August", "September", "October", "November",
							  "December" };

	int i;

	/* Display the months of the year using subscripts */
	printf("The months of the year are:\n\n");
	for(i = 0; i< 12; i++)
	  printf("%s\n", months[i]);


    /* Display the months of the year using pointer arithmetic */
	printf("The months of the year are:\n\n");
	for(i = 0; i< 12; i++)
	  printf("%s\n", *(months +i));
}
