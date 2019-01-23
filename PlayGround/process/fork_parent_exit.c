
/*
  在linux下，父进程被杀死而子进程仍然运行，则该子进程就变成了孤儿进程。
  如何终止父进程及其子进程

*/

#include <stdio.h>
#include <unistd.h>


void parent() {
    while(true) {
        sleep(5);
        printf("parent is running\n");
    }
}

void child() {
    while(true) {
        sleep(5);
        printf("child is running\n");
    }
}

int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid) {
    case -1:
        perror("fail to fork");
        break;
    case 0:
        printf("parent process");
        parent();
        break;
    default:
        printf("child process");
        child();
        break;
    }

    return 0;
}
