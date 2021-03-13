#include <stdio.h>

int main()
{
  int input[10] = {0};
  int i,j;


  printf("Enter a set of 10 numbers:\n");

  for (i = 0; i < 10; i++)
  {
    printf("Enter a number:");
    scanf("%d",&input);
  }


  for (i = 0; i <= input; i++)
  {
    printf("%d\n",input );
      printf("*");
  }
  return 0;
}
