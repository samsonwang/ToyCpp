
#include <iostream>

// 这道题考察的是数学能力吧，找到数学规律之后就是纯计算了。
// 唯一没有注意到的就是在连续相乘后，top需要使用long，以防止数据溢出

class Solution {
public:
    int uniquePaths(int m, int n) {
        int step = m + n - 2;
        if (step <= 1) {
            return 1;
        }

        int k = m > n ? n - 1 : m - 1;

        long top = 1;
        long bottom = 1;

        for (int i=0; i<k; ++i) {
            top *= (step-i);
        }

        for (int i=0; i<k; ++i) {
            bottom *= (k - i);
        }

        return top / bottom;
    }
};

int main(int argc, char* argv[]) {

    std::cout << "3, 2: " << Solution().uniquePaths(3, 2) << std::endl;

    std::cout << "3, 3: " << Solution().uniquePaths(3, 3) << std::endl;

    std::cout << "7, 3: " << Solution().uniquePaths(7, 3) << std::endl;

    std::cout << "0, 0: " << Solution().uniquePaths(0, 0) << std::endl;
    std::cout << "1, 1: " << Solution().uniquePaths(1, 1) << std::endl;
    std::cout << "1, 2: " << Solution().uniquePaths(1, 2) << std::endl;
    std::cout << "1, 3: " << Solution().uniquePaths(1, 3) << std::endl;
    return 0;
}
