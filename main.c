#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void) {
    pid_t pid = fork();
    for (int i = 0; i < 3; i ++) {
        if (pid == -1) {
            perror("fork");
            exit(0);
        }
        if (pid == 0) {
            printf("Sono il figlio il mio ritorno è %d il mio pid è %d mio padre è %d\n", pid, getpid(), getppid());
            sleep(2);
            exit(0);
        }

    }
    printf("Sono il padre il mio ritorno è %d il mio pid è %d\n", pid, getpid());
    wait(NULL);
    return 0;
}