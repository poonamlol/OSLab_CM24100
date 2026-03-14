#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        sleep(10);   
        printf("Parent process\n");
    } else {
        printf("Child process exiting\n");
    }
    return 0;
}
