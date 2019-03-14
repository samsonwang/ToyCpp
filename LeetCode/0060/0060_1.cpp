
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

// 穷举所有组合，排序后取得指定组合
// 这应该算是暴力解法，所以leetcode给出的结果是超时
class Solution {
public:
    string getPermutation(int n, int k) {
        generate(n);
        return m_nums[k-1];
    }

private:
    void generate(int n) {
        m_nums.clear();

        //
        std::list<std::list<int>> bfs;
        bfs.emplace_back(1, 1);

        while (!bfs.empty()) {
            std::list<int> temp = bfs.front();
            bfs.pop_front();

            if (temp.size() == size_t(n)) {
                std::string str;
                for (auto it = temp.begin();
                     it != temp.end(); ++it) {
                    str += char(*it + '0');
                }
                m_nums.push_back(str);
                continue;
            }

            int ins = temp.size() + 1;
            for (auto it = temp.begin();
                 it != temp.end(); ++it) {
                it = temp.insert(it, ins);
                bfs.push_back(temp);
                it = temp.erase(it);
            }
            temp.push_back(ins);
            bfs.push_back(temp);
        }

        std::sort(m_nums.begin(), m_nums.end());
    }

private:
    vector<string> m_nums;
};

int main(int argc, char* argv[]) {

    int n = 4;
    int k = 9;

    string ans = Solution().getPermutation(n, k);

    cout << "ans:" << ans << endl;

    return 0;
}
