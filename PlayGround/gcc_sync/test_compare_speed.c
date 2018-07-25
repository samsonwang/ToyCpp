
// 测试使用同步锁和原子化操作的性能差异
// 在单核环境下是否所有的操作都是原子操作呢？

#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

#define THREAD_COUNT 4
const int INC_COUNT = 1000000;

int g_nCounter = 0;
pthread_mutex_t g_mutex;


void* ThreadFunc(void* args);

int main(int argc, char *argv[])
{
    if (pthread_mutex_init(&g_mutex, NULL) != 0)
    {
        printf("pthread mutex init failed\n");
        return -1;
    }
    
    printf("g_nCounter = %d\n", g_nCounter);

    // create thread to increase g_nCounter
    pthread_t tids[THREAD_COUNT];
    int i;
    for (i=0; i<THREAD_COUNT; ++i)
    {
        pthread_create(&tids[i], NULL, ThreadFunc, NULL);
    }

    // wait for thread finish
    for (i=0; i<THREAD_COUNT; ++i)
    {
        pthread_join(tids[i], NULL);
    }
    
    printf("g_nCounter = %d (after inc)\n", g_nCounter);

    if (pthread_mutex_destroy(&g_mutex) != 0)
    {
        printf("pthread mutex destroy failed\n");
        return -1;
    }
    
    return 0;
}

void* ThreadFunc(void* args)
{
    struct timeval tv_start;
    struct timeval tv_end;

    gettimeofday(&tv_start, NULL);
    
    int i;
    for (i=0; i<INC_COUNT; ++i)
    {
        //        __sync_fetch_and_add(&g_nCounter, 1);
        pthread_mutex_lock(&g_mutex);
        ++g_nCounter;
        pthread_mutex_unlock(&g_mutex);
    }

    gettimeofday(&tv_end, NULL);

    time_t tSec = tv_end.tv_sec - tv_start.tv_sec;
    long int tDiff = tv_end.tv_usec - tv_start.tv_usec;
    printf("tSec = %ld, tDiff = %ld\n", tSec, tDiff);
}

