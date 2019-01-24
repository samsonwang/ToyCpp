
/*
  在linux下，父进程被杀死而子进程仍然运行，则该子进程就变成了孤儿进程。
  如何终止父进程及其子进程
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/prctl.h>

void parent() {
    int count = 0;
    while(true) {
        printf("parent: running\n");
        sleep(5);
        ++count;
        if (count > 3) {
            printf("parent: call exit\n");
            exit(0);
        }
    }
}

void child() {
    prctl(PR_SET_PDEATHSIG, SIGHUP);
    while(true) {
        printf("child : running\n");
        sleep(5);
    }
}

void proc_sighup(int sig) {
    printf("%05d :sighup received\n", getpid());
    exit(EXIT_SUCCESS);
}

int main(int argc, char* argv[]) {

    signal(SIGHUP, proc_sighup);

    switch (fork()) {
    case -1:
        perror("fail to fork");
        break;
    case 0:
        // printf("child process");
        printf("child : pid = %d, ppid = %d\n",
               getpid(), getppid());
        child();
        break;
    default:
        printf("parent: pid = %d\n", getpid());
        parent();
        break;
    }

    return 0;
}
