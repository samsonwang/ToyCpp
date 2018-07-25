
#include <stdio.h>

int main(int argc, char *argv[])
{

    int num1 = 0;

    printf("num1 = %d\n", num1);

    int num2 = __sync_fetch_and_add(&num1, 1);
    
    printf("num1 = %d, num2 = %d\n", num1, num2);
    
    return 0;
}

