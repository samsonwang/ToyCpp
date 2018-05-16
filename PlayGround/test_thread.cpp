
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct WorkerArgs
{
    const char* text;
    int offset_start;
    int offset_end;
}WorkerArgs;

int master(const char *text, int size, int n);
void* worker_thread(void* worker_args);
int worker(const char *text, int begin_offset, int end_offset);


int main(int argc, char* argv[])
{
    int nThreadCount = 5;
    if (argc > 1)
    {
        char* szParam = argv[1];
        int num = atoi(szParam);
        if (num > 0)
        {
            nThreadCount = num;
        }
    }

    
    int fd = open("./test_file", O_RDONLY);
    if (fd == -1)
    {
        perror("open failed:");
        return -1;
    }

    char* szBuffer = new char[102400]; // 100k

    ssize_t nSize = read(fd, szBuffer, 102400);
    
    int nWordCount = master(szBuffer, nSize, nThreadCount);
    
    printf("WordCount: %d\n", nWordCount);

    delete[] szBuffer;
    szBuffer = NULL;
    
    return 0;
}

// master在分割时，需要注意不要将一个单词分到两段
int master(const char *text, int size, int n)
{
    // 确定合适的大小
    int part_count = size / 100;
    part_count = part_count > n ? n : part_count;
    part_count = part_count > 1 ? part_count : 1;
    int part_size = size / part_count;
    
    std::vector<pthread_t> tids;

    int offset_start = 0;
    WorkerArgs worker_args;
    worker_args.text = text;
    
    do {
        int offset_end = offset_start + part_size;
        while (offset_end < size)
        {
            char ch = text[offset_end];
            ++offset_end;
            if (ch == ' ' || ch == '\n')
            {
                break;
            }
        }

        worker_args.offset_start = offset_start;
        worker_args.offset_end = offset_end;

        printf("+master: new thread start=%d end=%d\n", offset_start, offset_end);
        
        pthread_t tid;
        int ret = pthread_create(&tid, NULL, worker_thread, (void*)&worker_args);
        if (ret != 0)
        {
            continue;
        }
        
        tids.push_back(tid);

        offset_start = offset_end + 1;
        
        usleep(5);
        
    } while (offset_start < size);
        
    int total_word_count = 0;
    for (size_t i=0; i<tids.size(); ++i)
    {
        pthread_t tid = tids[i];
        int part_word_count = 0;
        int ret = pthread_join(tid, (void**)&part_word_count);
        if (ret == 0)
        {
            total_word_count += part_word_count;
        }
    }
    
    return total_word_count;
}

void* worker_thread(void* worker_args)
{
    WorkerArgs* pArgs = (WorkerArgs*)worker_args;
    if (!pArgs)
    {
        return NULL;
    }
    printf("*worker_thread: start=%d end=%d\n",
           pArgs->offset_start, pArgs->offset_end);

    return (void*)worker(pArgs->text, pArgs->offset_start, pArgs->offset_end);
}

int worker(const char *text, int begin_offset, int end_offset)
{
    if (text == NULL)
    {
        return 0;
    }
    
    // 当前worker对象的数量
    int part_word_count = 0;

    int offset = begin_offset;
    // 消除最开始空格和换行
    while (text[offset] == ' ' || text[offset] == '\n')
    {
        ++offset;
    }
    
    bool is_word_end = false;
    while (offset < end_offset)
    {
        char ch = text[offset];
        if (ch == ' ' || ch == '\n')
        {
            if (!is_word_end)
            {
                ++part_word_count;
                is_word_end = true;
            }
        }
        else
        {
            is_word_end = false;
        }
        ++offset;
    }

    printf("-worker: start=%d end=%d count=%d\n",
           begin_offset, end_offset, part_word_count);
    
    return part_word_count;
}


