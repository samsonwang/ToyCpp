
// leetcode sample, 8ms faster than 100%
// 使用的仍然是DP方法，简化掉所有的不必要的操作，就能够实现运行速度的提升

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();

        for (int x = 1; x < w; ++x)
            grid[0][x] += grid[0][x - 1];

        for (int y = 1; y < h; ++y) {
            auto& gridy = grid[y];
            gridy[0] += grid[y - 1][0];

            for (int x = 1; x < w; ++x) {
                gridy[x] += min(gridy[x - 1], grid[y - 1][x]);
            }
        }

        return grid[h - 1][w - 1];
    }
};
