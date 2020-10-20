#include <stdio.h>

#define NO_OF_MONTHS 12

//for matrix array
#define ROW 3
#define COL 2

int main()
{
  int months[NO_OF_MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
                            //0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
  
  //display days in each month
  for (size_t i = 0; i < NO_OF_MONTHS; i++)
  {
    printf("%d\n",months[i]);
  }

  //matrix array



}
