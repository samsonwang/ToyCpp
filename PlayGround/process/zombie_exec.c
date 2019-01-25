#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// this also make a zombie process by ls

int main() {
    switch(fork()) {
    case -1:
        printf("fail to create subprocess\n");
        break;
    case 0:
        printf("child process, pid = %d\n", getpid());
        execl("/usr/bin/ls", "-l");
        sleep(10);
        break;
    default:
        printf("parent process, pid = %d\n", getpid());
        sleep(30);
        break;
    }
    return 0;
}
