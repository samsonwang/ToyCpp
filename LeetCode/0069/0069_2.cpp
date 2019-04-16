

#include <iostream>

// 使用二分查找的思想

// 通过这道题，得到的教训是如果数值比较大，要提前进行宽度拓展，
// 否则计算结果仍然按照原始的数据类型存储了，达不到防止OV的作用

class Solution {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = x;

        while (left < right) {
            long long mid = (left+right)/2; // 这里使用 int 可能会出现OV
            long long down = mid * mid;
            long long up = (mid+1) * (mid+1);
            if (down <= x && up > x) {
                return int(mid);
            }

            if (down > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return int(left);
    }
};

int main(int argc, char* argv[]) {

    std::cout << "sqrt(4) = " << Solution().mySqrt(4) << std::endl;

    std::cout << "sqrt(8) = " << Solution().mySqrt(8) << std::endl;

    std::cout << "sqrt(9) = " << Solution().mySqrt(9) << std::endl;

    std::cout << "sqrt(12) = " << Solution().mySqrt(12) << std::endl;

    std::cout << "sqrt(100) = " << Solution().mySqrt(100) << std::endl;

    std::cout << "sqrt(2147395599) = " << Solution().mySqrt(2147395599) << std::endl;

    std::cout << "sqrt(2147483647) = " << Solution().mySqrt(2147483647) << std::endl;

    return 0;
}
