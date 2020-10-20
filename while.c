/*
*This is a calculator program
*/

/*
*Author: Arshad shah
*Created on: 10 october 2019.
*/

#include <stdio.h>

int main ()
{
  int num,total;

  total = 0 ;
  num = 1 ;

  /*
  Keep running sum for a set of numbers
  */
  while ( num != 0)
  {
    printf("\nEnter any whole number\n");
    scanf("%d",&num );

    //add num is total
    total = num + total;
  }//end while

  printf("\nTotal is %d",total );
  return 0;

}//end of main
