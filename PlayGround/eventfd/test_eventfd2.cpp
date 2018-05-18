

#include <sys/eventfd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include <inttypes.h>

#define UNUSED(x) (void)(x)

int main(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    
    int efd = eventfd(0, 0);
    printf("eventfd=%u\n", efd);
    
    printf("before fork: pid=%u\n", getpid());
    
    pid_t pid = fork();
    // parent
    if (pid == 0)
    {
        printf("after fork: pid=%u ppid=%u\n", getpid(), getppid());
        
        int64_t val = 0;
        for (int i=0; i<5; ++i)
        {
            val = i+1;
            ssize_t ret = write(efd, (const void*)&val, sizeof val);
            if (ret < 0)
            {
                perror("write to eventfd failed: ");
            }
            else
            {
                printf("write to eventfd: %lld\n", val);
            }
        }

        exit(0);
    }
    // child
    else
    {
        printf("after fork: pid=%u ppid=%u\n", getpid(), getppid());
        usleep(100);

        int64_t val = 0;
        ssize_t ret = read(efd, (void*)&val, sizeof val);
        if (ret < 0)
        {
            perror("read from eventfd failed: ");
        }
        else
        {
            printf("read from eventfd: %lld\n", val);
        }

        exit(0);
    }
    
    return 0;
}


