/*program that uses calloc() for memory allocation*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *ptr;
  int no_of_nums;
  int no_bytes;
  int i;

  printf("How many numbers to enter?\n");
  scanf("%d\n",&no_of_nums);

  //allocate the memory required
  ptr = calloc(no_of_nums, sizeof(int));

  //check if memory allocated successfully
  if (ptr == NULL)
  {
    printf("Failed to allocate memory\n");
  }
  else
  {
    //enter data into memory block
    for (i = 0; i < no_of_nums; i++)
    {
      scanf("%d\n",&*(ptr+i));
    }//end of for

    //diplay data inside memory block
    for (i = 0; i < no_of_nums; i++)
    {
      printf("%d\n",*(ptr+i));
    }//end of for
  }//end of if else

  //release memory block
  free(ptr);

  return 0;
}
