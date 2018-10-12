

#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cinttypes>

// leetcode solution, fastest， 4ms
// 我之前都是以除数为操作对象的，而这个方法使用被除数作为操作对象
int divide(int dividend, int divisor) {
    unsigned int a = (dividend >= 0)
        ? static_cast<unsigned int>(dividend)
        : (0 - static_cast<unsigned int>(dividend));

    unsigned int b = (divisor >= 0)
        ? static_cast<unsigned int>(divisor)
        : (0 - static_cast<unsigned int>(divisor));

    unsigned int n = 0;
    for (unsigned i = a; i >= b; i = i >> 1) {
        ++n;
    }
    unsigned int result = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a >= (b << i)) {
            result = result | (1 << i);
            a -= (b << i);
        }
    }
    if ((dividend >= 0) == (divisor >= 0)) {
        return static_cast<int>(min(result, static_cast<unsigned int>(INT_MAX)));
    } else {
        return static_cast<int>(0 - result);
    }
}

int main(int argc, char* argv[])
{
    int d1 = 10;
    int d2 = 3;

    int ret = divide(d1, d2);

    printf("d1 = %d(0x%x), d2 = %d(0x%x), ret = %d(0x%x)\n",
           d1, d1, d2, d2, ret, ret);

    //    int t1 = std::pow(2, 31) - 1;

    //    printf("t1 = 0x%x , %lld\n", t1, t1);

    //    printf("0x%x\n", -2147483648);

    return 0;
}
