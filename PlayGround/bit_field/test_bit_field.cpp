
#include <cstdio>

struct stu0
{
    int n1;
    int n2;
};

struct stu1
{
    int n1 : 3;
    int n2 : 2;
};

union un0
{
    int n1;
    struct
    {
        int nn1 : 16;
        int nn2 : 16;
    } st;
};

union un1
{
    int n1;
    class
    {
    public:
        int nn1 : 8;
        char : 0;
        int nn2 : 16;
    } st;
};

int main(int argc, char *argv[])
{
    printf("sizeof(stu0) = %zu\n", sizeof(stu0));

    printf("sizeof(stu1) = %zu\n", sizeof(stu1));

    printf("sizeof(un0) = %zu\n", sizeof(un0));


    un0 u1;
    u1.st.nn1 = 1;
    u1.st.nn2 = 1;

    un0 u2;
    u2.n1 = 0x010001;

    printf("union u1.n1=%d u2.n1=%d\n", u1.n1, u2.n1);
    printf("union u1.n1=0x%08x u1.st.nn1=0x%04x u1.st.nn2=0x%04x\n", u1.n1, u1.st.nn1, u1.st.nn2);
    printf("union u2.n1=0x%08x u2.st.nn1=0x%04x u2.st.nn2=0x%04x\n", u2.n1, u2.st.nn1, u2.st.nn2);

    un1 u3;
    u3.st.nn1 = 1;
    u3.st.nn2 = 1;
    printf("union u3.n1=0x%08x  sizeof(un1)=%zu\n", u3.n1, sizeof(un1));
    
    return 0;
}


