

#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cinttypes>

// 根据提示使用位运算
// 这种方法还是比较笨的，而且使用的时间也很长 1660ms
int divide(int dividend, int divisor) {

    printf("**dividend = %d(0x%x) divisor = %d(0x%x)\n",
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

    // 这样两个数的符号都是正的了
    int count = 0;
    std::int64_t pow = 0;
    std::int64_t d2_pre = 0; // 防止溢出
    std::int64_t d2_roll = d2;
    while (d1 >= d2_roll) {
        d2_pre = d2_roll;
        d2_roll = d2_roll << 1;
        ++count;
        if (pow == 0) {
            pow = 1;
        }
        else {
            pow += pow; // x2效果
        }
    }

    printf("**count=%" PRId64 "(0x%x), pow=%" PRId64 "(0x%x)\n",
           count, count, pow, pow);

    // 剩余部分
    std::int64_t remain = d1 - d2_pre;
    int remain_ans = 0;
    while (remain >= d2) {
        remain -= d2;
        ++remain_ans;
    }

    printf("**reamin_ans=%" PRId64 "(0x%x)\n",
           remain_ans, remain_ans);

    std::int64_t ans = pow + remain_ans;

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
