#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *print_message_function(void *ptr);

int main(int argc, char const *argv[]) {
  pthread_t thread1, thread2;
  char *message1 = "I am a Thread 1\n";
  char *message2 = "I am Thread 2\n";
  int iret1, iret2;

  //create independent threads each of which will execute function

  iret1 = pthread_create(&thread1, NULL, print_message_function, (void*)message2);
  iret2 = pthread_create(&thread2, NULL, print_message_function, (void*)message1);

  pthread_join(thread1,NULL);
  pthread_join(thread2, NULL);

  printf("Thread 1 returns: %d\n", iret1);
  printf("Thread 2 returs: %d\n",iret2 );
  printf("end of main program\n");
  exit(0);
  return 0;
}

void *print_message_function(void *ptr)
{
  char *message;
  message = (char *) ptr;
  printf("%s \n", message );

}
