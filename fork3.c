..
cpid = fork();
if (cpid > 0) {  /** Parent process */
  tcpid = wait(&status);
} else if (cpid == 0) {
  char *args[] = {"ls", "-l", NULL};
  execv("/bin/ls", args);

  /* execv doesn't return when it works.
   * So, if we got here, it failed. */

  perror("execv");
  exit(1);
}
...
