#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int status;
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Helloe!\n");
    }
    else
    {
        while (waitpid(rc, &status, 0) == 0)
        {
            sleep(1);
        }
        printf("Goodbye!\n");
    }
}