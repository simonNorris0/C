#include <windows.h>
#include <stdio.h>
DWORD Sum; /* globally declared data is shared by the thread(s) */

/* The thread will execute in this function 
   sets the global data Sum to the value of the summation from 
   0 to the parameter passed as Param.
*/
DWORD WINAPI Summation(LPVOID Param)
{
  DWORD Upper = *(DWORD*)Param;
  for (DWORD i = 1;  i <= Upper; i++)
    Sum += i;
  return 0;
}

int main(int argc, char *argv[])
{
  DWORD ThreadID;;
  HANDLE ThreadHandle;
  int Param;

  if(argc == 1) {
    printf("run with a single command-line arg, a positive integer to sum.");
    return 1;
  }

  Param = atoi(argv[1]);

  /* Threads are created in the Windows API using the CreateThread() function. 
     Just as with Pthreads from the POSIX API, a set of attributes for the 
     thread is passed to this function. These attributes include:
     - security information
     - the size of the stack
     - a flag that can be set to indicate if the thread is to start in a 
       suspended state
  */
  ThreadHandle = CreateThread(
    NULL,       /* default security attributes */
    0,          /* default stack size */
    Summation,  /* thread function */
    &Param,     /* parameter to thread function */
    0,          /* default creation flags - does not set the thread to a 
                   suspended state, instead makes it eligible to be run 
                   by the CPU scheduler */
    &ThreadID); /* returns the thread identifier */

  /* now wait for the thread to finish 
     equivalent of pthread_join()
  */
  WaitForSingleObject(ThreadHandle, INFINITE); 
  /* WaitForMultipleObjects() function is used in situations that require 
     waiting for multiple threads to complete. WaitForMultipleObjectS()
     takes four parameters: 
     - the number of objects to wait for
     - a pointer to the array of objects 
     - a flag indicating whether all objects have been signaled 
     - a timeout duration (or INFINITE)
  */

  /* close the thread handle */
  CloseHandle(ThreadHandle);

  printf("sum = %d\n", Sum);
}