
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

static auto fast = [] {
                       std::ios::sync_with_stdio(false);
                       std::cin.tie(0);
                       std::cout.tie(0);
                       return 0;
                   }();

// 找出组合的排列规律
class Solution {
public:
    string getPermutation(int n, int k) {
        generateFactorial(n);

        std::list<int> nums;
        for (int i=1; i<=n; ++i) {
            nums.push_back(i);
        }

        std::string ans;

        while (n > 1) {
            int div = k / m_factorials[n-1];
            int remain = k % m_factorials[n-1];
            if (remain == 0) {
                --div;
            }

            // 取得数字，并将数字删除
            auto it = nums.begin();
            while ( div > 0) {
                ++it;
                --div;
            }

            int digit = *it;
            nums.erase(it);

            k = remain;
            --n;

            ans += char('0' + digit);
        }

        ans += char('0' + nums.front());

        return ans;
    }

private:
    // 生成阶乘以备用
    void generateFactorial(int n) {
        m_factorials.push_back(0);
        int base = 1;
        for (int i=1; i<n; ++i) {
            base *= i;
            m_factorials.push_back(base);
        }
    }

private:
    std::vector<int> m_factorials;
};

int main(int argc, char* argv[]) {

    int n = 3;
    int k = 3;

    string ans = Solution().getPermutation(n, k);

    cout << "ans:" << ans << endl;

    return 0;
}
