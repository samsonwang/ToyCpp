

#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cinttypes>

// 根据提示使用位运算
// 这种方法还是比较笨的，而且使用的时间也很长 1660ms
int divide(int dividend, int divisor) {
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

    std::int64_t ans = 0;

    // 这样两个数的符号都是正的了
    while (d1 >= d2) {
        std::int64_t pow = 1;
        std::int64_t roll = d2;
        while (d1 >= roll << 1) {
            roll = roll << 1;
            pow += pow; // x2效果
        }
        d1 -= roll;
        ans += pow;
    }

    printf("**ans=%" PRId64 "(0x%x)\n",
           ans, ans);

    if (neg) {
        ans = -ans;
    }

    if (ans > 0x7fffffff) {
        return 0x7fffffff;
    }

    return ans;
}

int main(int argc, char* argv[])
{
    int d1 = 0x7fffffff;
    int d2 = 1;

    int ret = divide(d1, d2);

    printf("d1 = %d(0x%x), d2 = %d(0x%x), ret = %d(0x%x)\n",
           d1, d1, d2, d2, ret, ret);

    //    int t1 = std::pow(2, 31) - 1;

    //    printf("t1 = 0x%x , %lld\n", t1, t1);

    //    printf("0x%x\n", -2147483648);

    return 0;
}
