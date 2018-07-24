
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("page size = %d", getpagesize());
    return 0;
}

