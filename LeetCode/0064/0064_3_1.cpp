
#include <vector>
#include <iostream>
#include <list>
#include "../../shared/stream.h"

using namespace std;

// 使用DP法
// 对空间加以优化，每次迭代的时候只需要本行和上一行的数据

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

        vector<int> pre = grid[0];
        for (size_t i=1; i<n; ++i) {
            pre[i] += pre[i-1];
        }

        vector<int> curr;
        for (size_t j=1; j<m; ++j) {
            curr = grid[j];
            curr[0] += pre[0];
            for (size_t i=1; i<n; ++i) {
                curr[i] += min(pre[i], curr[i-1]);
            }
            pre = curr;
        }

        // 1x1 大小的矩阵
        if (curr.empty()) {
            return pre[n-1];
        }
        else {
            return curr[n-1];
        }

    }
};

// 下面这个solution摘自leetcode，看起来更加优雅
class Solution_2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);
        for (int i = 1; i < m; i++)
            pre[i] = pre[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) {
            cur[0] = pre[0] + grid[0][j];
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];
            swap(pre, cur);
        }
        return pre[m - 1];
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
