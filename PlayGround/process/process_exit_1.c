
#include <stdio.h>
#include <stdlib.h>

void cleanup() {
    printf("cleanup ...\n");
}

int main(int argc, char* argv[]) {

    printf("process running ...\n");

    atexit(cleanup);

    printf("buffer information ...");

    exit(0);

    return 0;
}
