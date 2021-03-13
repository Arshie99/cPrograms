#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


//functions prototypes
void parse(char *, char **);
void execute(char **);


void main(void)
{
  char line[1024];//the input line
  char *argv[64];//the argument

  //repeat code until the argument is done
  while (1)
  {
    //display prompt
    printf("Shell (enter exit to finish) -> ");
    //take input
    fgets(line,1024,stdin);

    //call parse function
    parse(line,argv);
    //check if argument is an exit
    if (strcmp(argv[0], "exit") == 0)
    {
      printf("Exit program");
      exit(0);
    }
    //call the execute function
    execute(argv);
  }
}//end of main

/*
  This function takes the plain text line and parses it into a argument
*/
void parse(char *line, char **argv)
{
  //if not the end of line
  while (*line != '\0')
  {
    //then replace whitespaces with 0
    while (*line == ' ' || *line == '\t' || *line == '\n')
    {
      *line++ == '\0';
    }
    *argv++ = line;

    //skip the argument
    while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n')
    {
      *line++;
    }
  }
  //mark the end of argument list
  *argv = '\0';
}

void execute(char **argv)
{
  //initialize and declare variables
  pid_t pid;
  int status;

  //fork a child process
  if ((pid = fork()) < 0 )
  {
    printf("*** ERROR: forking child process failed\n ");
    exit(1);
  } else if (pid == 0)
  {//for child process
    if (execvp(*argv, argv) < 0)
    {
      printf("*** ERROR: Execute failed");
      exit(1);
    }
  }
  else
  {
    //for the parent
    printf("before the wait command \n");
    while (wait(&status) != pid)
    {
      printf("after the wait command\n");
    }
  }
  printf("end execute");
}
