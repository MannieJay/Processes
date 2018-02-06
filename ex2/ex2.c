// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  int c, rc;
  printf("hello world (pid: %d) and text: %c\n", (int)getpid(), c);
  FILE *fp;
  int c;

  fp = fopen("text.txt", "r");
  while (1)
  {
    c = fgetc(fp);
    if (feof(fp))
    {
      break;
    }
    printf("%c", c);
  }
  fclose(fp);

  rc = fork();

  if (rc < 0)
  { // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  { // child process satisfies this branch
    printf("hello, child here (pid: %d) and text: %c\n", (int)getpid(), c);
  }
  else
  {
    printf("hello, parent here (pid: %d) of child %d and text: %c\n", (int)getpid(), rc, c);
  }

  return 0;
}