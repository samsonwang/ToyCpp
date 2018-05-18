
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/eventfd.h>
#include <sys/select.h>

#define UNUSED(x) (void)(x)

void* func_child(void* args);

int main(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    
    int efd = eventfd(0, 0);
    if (efd == -1)
    {
        perror("eventfd failed");
        return -1;
    }
    printf("master thread: efd=%d\n", efd);

    pthread_t tid;
    int ret = pthread_create(&tid, NULL, func_child, (void*)&efd);
    if (ret != 0)
    {
        perror("pthread_create failed");
        return -1;
    }

    int64_t val = 0;
    while(true)
    {
        ++val;
        
        ssize_t ret = write(efd, (const void*)&val, sizeof(val));
        if (ret == -1)
        {
            perror("master thread write failed");
        }
        else
        {
            printf("master thread write %lld\n", val);
        }

        // write to efd every 1 second
        sleep(1);
    }
    
    ret = pthread_join(tid, NULL);
    if (ret != 0)
    {
        perror("pthread_join failed");
    }
    
    return 0;
}

void* func_child(void* args)
{
    int efd = *((int*)(args));
    printf("child thread: efd=%d\n", efd);

    int64_t val = 0;
    int nCount = 10;
    fd_set objFdSet;

    /*
      struct timeval objTimeout;
      objTimeout.tv_sec = 1;
      objTimeout.tv_usec = 0;
    */
    
    do {
        FD_ZERO(&objFdSet);
        FD_SET(efd, &objFdSet);
        
        int ret = select(efd+1, &objFdSet, NULL, NULL, NULL);
        if (ret < 0)
        {
            perror("select failed");
        }
        else
        {
            ret = read(efd, (void*)&val, sizeof(val));
            if (ret == -1)
            {
                perror("read failed:");
            }
            else
            {
                printf("child read: %lld\n", val);
            }
        }
        
        --nCount;
    }while(nCount > 0);

    printf("child thread calls exit\n");
    exit(0);
    
    return NULL;
}



