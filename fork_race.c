#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char *argv[])
{
  int i; // both processes have their own addres spaces,
         // and their own separate i's
  pid_t cpid = fork();
  // and both start running immediately after fork(), 
  // each takes its own path through the rest of the code
  if (cpid > 0) {
    for (i=0; i<10; i++) {
      printf("Parent: %d\n", i);
    }
  } else if (cpid == 0) {
    for (i=0; i>-10; i--) {
      printf("Child: %d\n", i); 
    }
  } else { // cpid < 0 
      printf("Error from fork()");  
  }
}
