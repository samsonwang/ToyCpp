
#include <stdio.h>

typedef union un
{
    int x;
    char ch[2];
}un;


int main(int argc, char* argv[])
{
    un u;
    u.ch[0] = 10;
    u.ch[1] = 1;
    u.ch[2] = 2;
    u.ch[3] = 3;

    printf("u.x=%d\n", u.x);
    printf("u.x=0x%x\n", u.x);

    int n = 07;
    const char* szStr = "test";
    
    return 0;
}




