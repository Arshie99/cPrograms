/*
  @Author: Arshad Shah
  @Date:   Tuesday, October 13, 2020 11:27 AM
  @Email:  C19485866@mytudublin.ie
  @Filename: LinkedList.c
  @Last modified by:   Arshad Shah
  @Last modified time: Tuesday, October 13, 2020 12:02 PM
*/


//header files
#include <stdio.h>
#include <stdlib.h>

//structures
struct node
{
  int data;//the data
  struct node *next;//the pointer to the next location
};



//main
int main(int argc, char const *argv[])
{
  //create nodes and initialize variables
  struct node *prev,*head,*p;
  int i,n;

//number of elements in list
  printf("number of elements:");
  scanf("%d",&n );
  head=NULL;

  //join the nodes
  for (i = 0; i < n; i++)
  {
    //put values in the nodes
    p = malloc(sizeof(struct node));
    scanf("%d",&p->data );
    p->next=NULL;

    //if statement to create or not create the list
    if (head=NULL)
    {
      head=p;
    }
    else
    {
      prev->next=p;

    }
    prev=p;
  }
  return 0;
}



//function for looking in a LinkedList
display(struct node *head)
{
    //temporary node to print
    struct node *tmp;
    tmp = head;
    while(tmp != NULL)
    {
        printf("%d\n",tmp->data);
        tmp = tmp->next;
    }
}
