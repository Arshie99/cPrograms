#include <stdio.h>
//for matrix array
#define ROW 3
#define COL 2

int main()
{
  int matrix[ROW][COL];
  int i;
  int j;
  //display
  for (i = 0; i < ROW; i++)
  {
    for (j = 0; j < COL; j++)
    {
      scanf("%d\n",&matrix[i][j] );
    }
  }

  //display then numbers
  for (i = 0; i < ROW; i++)
  {
    for (j = 0; j < COL; j++)
    {
      printf(" %d\n",matrix[i][j] );
    }
  }


  //matrix array



}
