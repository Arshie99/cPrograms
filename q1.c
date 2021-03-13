#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT 20

void childProcess(void);
void parentProcess(void);


int main(int argc, char **argv)
{
  pid_t pid;
  pid = fork();

  if (pid < 0)
  {
    printf("error unable to fork process; ending program");
  }

  if (pid == 0)
  {
    childProcess();
  }
  else
  {
    printf("the fork command returns PID of the child: %d\n",pid );
    parentProcess();
  }
}

void childProcess()
{
  int i, x , pid1, pid2;

  pid1 = getpid();

  for (i = 0; i <= MAX_COUNT; i++)
  {
    printf("this line is from child (pid number %d) the pid of the parent is %d, value =  %d\n", pid1,pid2,i );
    for ( x = 0; x < 10000000000; x++)
    {
      printf("child process is done\n");
    }
  }
}

void parentProcess()
{
  int i, x, pid1;

  pid1 = getpid();

  for (i = 1; i < MAX_COUNT; i++)
  {
    printf("this line is from parent (pid number %d), value =  %d\n", pid1,i );
    for ( x = 0; x < 10000000000; x++);
  }
  printf("Parent is done\n");
}
