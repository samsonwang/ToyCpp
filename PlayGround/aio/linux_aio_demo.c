// link: https://gist.github.com/larytet/87f90b08643ac3de934df2cadff4989c

/**
 * Based on https://www.fsl.cs.sunysb.edu/~vass/linux-aio.txt
 * Compile gcc -Wall test_aio.c -o test_aio
 * Run rm -rf /tmp/testfile ;./iotest
 */

#define _GNU_SOURCE     /* syscall() is not POSIX */

#include <stdio.h>      /* for perror() */
#include <unistd.h>     /* for syscall() */
#include <sys/syscall.h>    /* for __NR_* definitions */
#include <linux/aio_abi.h>  /* for AIO types and constants */
#include <fcntl.h>      /* O_RDWR */
#include <string.h>     /* memset() */
#include <inttypes.h>   /* uint64_t */
#include <time.h>       /* time() */
#include <stdlib.h>     /* malloc */

static int io_setup(unsigned nr, aio_context_t *ctxp)
{
    return syscall(__NR_io_setup, nr, ctxp);
}

static int io_destroy(aio_context_t ctx)
{
    return syscall(__NR_io_destroy, ctx);    
}

static int io_submit(aio_context_t ctx, long nr,  struct iocb **iocbpp)
{
    return syscall(__NR_io_submit, ctx, nr, iocbpp);
}

static int io_getevents(aio_context_t ctx, long min_nr, long max_nr,
                        struct io_event *events, struct timespec *timeout)
{
    return syscall(__NR_io_getevents, ctx, min_nr, max_nr, events, timeout);
}

int main()
{
    aio_context_t ctx;
    struct iocb cb;
    struct iocb *cbs[1];
    void* data = malloc(409600);
    struct io_event events[1];
    int ret;
    int fd;

    fd = open("./aio_testfile", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("open error");
        return -1;
    }

    ctx = 0;

    ret = io_setup(128, &ctx);
    if (ret < 0) {
        perror("io_setup error");
        return -1;
    }

    /* setup I/O control block */
    memset(&cb, 0, sizeof(cb));
    cb.aio_fildes = fd;
    cb.aio_lio_opcode = IOCB_CMD_PWRITE;

    /* command-specific options */
    //    cb.aio_buf = (uint64_t)data;
    cb.aio_buf = (uint64_t)data;
    cb.aio_offset = 0;
    cb.aio_nbytes = 409600;

    cbs[0] = &cb;

    printf("%ld io_submit start\n", time(0));
    ret = io_submit(ctx, 1, cbs);
    if (ret != 1) {
        if (ret < 0)
            perror("io_submit error");
        else
            fprintf(stderr, "could not sumbit IOs");
        return  -1;
    }
    printf("%ld io_submit end\n", time(0));

    /* get the reply */
    printf("%ld io_getevents start\n", time(0));
    ret = io_getevents(ctx, 1, 1, events, NULL);
    printf("%ld io_getevents end (ret=%d)\n",
           time(0), ret);

    ret = io_destroy(ctx);
    if (ret < 0) {
        perror("io_destroy error");
        return -1;
    }

    free(data);
    
    return 0;
}


