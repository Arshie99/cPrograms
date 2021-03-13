/*
  @Author: Arshad Shah
  @Date:   Friday, October 9, 2020 11:43 AM
  @Email:  C19485866@mytudublin.ie
  @Filename: lab3_1.c
  @Last modified by:   Arshad Shah
  @Last modified time: Friday, October 9, 2020 12:50 PM
*/
#include <stdio.h>


//symbolic names
#define ROW 3
#define COL 3
#define RESULT 3



int main()
{
  //declare variables
  int first_matrix[ROW][COL];
  int second_matrix[ROW][COL];
  int result_matrix[ROW][COL];
  int i,j,k;
  int product;


printf("Matrix 1\n");
  //input for the matrix1
  for (i = 0; i < ROW; i++)
  {
    for (j = 0; j < COL; j++)
    {
      //matix 1 input
      printf("Element row %d column %d of matrix 1: ", i, j  );
      scanf("%d",&first_matrix[i][j] );

    }//end of for loop for j

  }//end of for loop for i

printf("\nMatrix 2\n");
  //input for the matrix 2
  for (i = 0; i < ROW; i++)
  {
    for (j = 0; j < COL; j++)
    {
      //matix 1 input
      printf("Element row %d column %d of matrix 2: ", i, j  );
      scanf("%d",&second_matrix[i][j] );

    }//end of for loop for j

  }//end of for loop for i



  //output matrices
  printf("\nMatrix 1\n");
    //print matrix 1
    for (i = 0; i < ROW; i++)
    {
      for (j = 0; j < COL; j++)
      {
        //matrix 1 input
        printf("%d\t",first_matrix[i][j]);
      }//end of for loop for j
      printf("\n");
    }//end of for loop for i


    printf("\nMatrix 2\n");
      //print matrix 1
      for (i = 0; i < ROW; i++)
      {
        for (j = 0; j < COL; j++)
        {
          //matrix 1 input
          printf("%d\t",second_matrix[i][j]);
        }//end of for loop for j
        printf("\n");
      }//end of for loop for i



      //multiplication of the matrices
      printf("\nMultiplying matrices...............\n");

        for (i = 0; i < ROW; i++)
        {

          for (j = 0; j < COL; j++)
          {
            //initialize product
            product = 0;
            for (k = 0; k < RESULT; k++)
            {
              product = product + first_matrix[i][k] * second_matrix[k][j];
            }//end of for loop for k

            result_matrix[i][j] = product;
          }//end of for loop for j

        }//end of for loop for i



//print result matrix
printf("\nResult of the 2 matrix\n");

  for (i = 0; i < ROW; i++)
  {
    for (j = 0; j < COL; j++)
    {
      //matrix 1 input
      printf("%d\t",result_matrix[i][j]);
    }//end of for loop for j
    printf("\n");
  }//end of for loop for i
  return 0;
}
