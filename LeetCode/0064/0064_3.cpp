
#include <vector>
#include <iostream>
#include <list>
#include "../../shared/stream.h"

using namespace std;

// 使用DP法
// 使用DP方法竟然AC了，实在是惊奇，只不过时间复杂度还是不够优化。
// AC的结果，耗时 16ms，优于24.15%的提交

// 如果加以优化，那么会耗时 12ms，优于98.28%的提交

static auto fast = []{
                       ios_base::sync_with_stdio(false);
                       cin.tie(nullptr);
                       return 0;
                   }();

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t m = grid.size();
        if (m == 0) {
            return 0;
        }
        size_t n = grid.front().size();

        vector<vector<int>>& dp = grid;

        for (size_t i=0; i<m; ++i) {
            for (size_t j=0; j<n; ++j) {
                int left = i>0 ? dp[i-1][j] : -1;
                int up = j>0 ? dp[i][j-1] : -1;

                if (left == -1 && up == -1) {
                    continue;
                }

                if (left == -1) {
                    dp[i][j] += up;
                }
                else if (up == -1) {
                    dp[i][j] += left;
                }
                else if (left < up) {
                    dp[i][j] += left;
                }
                else {
                    dp[i][j] += up;
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> grid;
    grid.push_back(vector<int>({1, 3, 1}));
    grid.push_back(vector<int>({1, 5, 1}));
    grid.push_back(vector<int>({4, 2, 1}));

    cout << "grid:" << endl;
    for (const auto& row : grid) {
        cout << row << endl;
    }
    int ret = Solution().minPathSum(grid);
    cout << "ret = " << ret << endl;

    return 0;
}
