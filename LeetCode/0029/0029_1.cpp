

#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cinttypes>

int divide(int dividend, int divisor) {

    printf("dividend = %d(0x%x) divisor = %d(0x%x)\n",
           dividend, dividend, divisor, divisor);

    std::int64_t d1 = dividend;
    std::int64_t d2 = divisor;

    // 符号转换
    bool neg = false;
    if (d1 < 0) {
        neg = !neg;
        d1 = -d1;
    }
    if (d2 < 0) {
        neg = !neg;
        d2 = -d2;
    }


    std::printf("d1 = %" PRId64 "(0x%x) d2 = %" PRId64 "(0x%x)\n",
                d1, d1, d2, d2);

    fflush(stdout);

    // 这样两个数的符号都是正的了
    int ans = 0;
    while (d1 >= d2) {
        d1 -= d2;
        ++ans;

        // overflow
        if (ans < 0) {
            return 0x7fffffff;
        }
    }

    if (neg) {
        return -ans;
    }

    return ans;
}

int main(int argc, char* argv[])
{
    int d1 = 2147483647;
    int d2 = 1;


    printf("dividend = %d(0x%x) divisor = %d(0x%x)\n",
           d1, d1, d2, d2);

    int ret = divide(d1, d2);

    printf("d1 = %d, d2 = %d, ret = %d\n",
           d1, d2, ret);


    int t1 = std::pow(2, 31) - 1;

    printf("t1 = 0x%x , %lld\n", t1, t1);

    //    printf("0x%x\n", -2147483648);

    return 0;
}
