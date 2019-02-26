
#include <string>
#include <iostream>

using namespace std;

// 穷举所有组合，排序后取得指定组合
class Solution {
public:
    string getPermutation(int n, int k) {
        generate(n);
        return m_nums[k];
    }

private:
    void generate(int n) {
        m_nums.clear();



    }

    vector<string> m_nums;
};

int main(int argc, char* argv[]) {

    int n = 3;
    int k = 3;

    string ans = Solution().getPermutation(n, k);

    cout << "ans:" << ans << endl;

    return 0;
}
