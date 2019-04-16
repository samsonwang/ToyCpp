

#include <iostream>

// 由于一提示我 int overflow，所以才出现了下面这种非常不优雅的代码
class Solution {
public:
    int mySqrt(int x) {

        for (int i = 1; i < 46341; ++i) {
            int n = i*i;
            if (n == x) {
                return i;
            }
            if (i*i > x) {
                return i-1;
            }
        }

        return 46340;
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
