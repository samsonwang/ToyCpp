
#include <cstdio>
#include "Singleton.h"

int main(int argc, char *argv[]) {

    printf("singleton, main begin\n");

    Singleton::Instance().Foo();

    printf("singleton, main end\n");

    return 0;
}
