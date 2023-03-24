#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
char *custom_env[] = {"USER=Pikachu", "PATH=/tmp", NULL};

int main(void)
{

    printf("Running parent process PID: %d\n\n", getpid());

    // fork the first child
    pid_t child1 = fork();

    if (child1 == 0) {
        printf("Running child process PID: %d\n", getpid());
        execle("echoall", "echoall", "Bandicoot", "Pacman", NULL, custom_env);
        // terminate
        exit(1);
    }

    // wait for child 1 to terminate
    waitpid(child1, NULL, 0);

    // fork the second child
    pid_t child2 = fork();

    if (child2 == 0) {
        printf("Running child process PID: %d\n", getpid());
        execlp("echoall", "echoall", "Spyro", NULL);
        // terminate
        exit(1);
    }

    // wait for child 2 to terminate
    waitpid(child2, NULL, 0);

    exit(0);
}