/* parent waits for child to finish */

int status;
pid_t tcpid;
...
cpid = fork();
if (cpid > 0) { /* Parent process */
  mypid = getpid();
  printf("[%d] parent of [%d]\n", mypid, cpid);
  tcpid = wait(&status);
  printf("[%d] bye %d(%d)\n", mypid, tcpid, status)
} else if (cpid == 0) { /* Child process */
  mypid = getpid();
  printf("%d] child\n", mypid);
  exit(42);
}
...
