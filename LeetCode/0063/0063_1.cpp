

#include <vector>
#include <iostream>
#include "../../shared/stream.h"


using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        size_t m = obstacleGrid.size();
        if (m == 0) {
            return 0;
        }
        size_t n = obstacleGrid.front().size();

        vector<vector<long>> dp(m, vector<long>(n, 0));

        for (size_t i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }

        for (size_t i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            dp[0][i] = 1;
        }

        for (size_t i=1; i<m; ++i) {
            for (size_t j=1; j<n; ++j) {
                dp[i][j] = 0;
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                if (obstacleGrid[i-1][j] == 0) {
                    dp[i][j] += dp[i-1][j];
                }
                if (obstacleGrid[i][j-1] == 0) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};

/*
  Submission result:
  Runtime: 4 ms, faster than 100.00% of C++ online submissions for Unique Paths II.
  Memory Usage: 9.3 MB, less than 23.95% of C++ online submissions for Unique Paths II.

  从提交的结果来看，空间复杂度有待提高。
*/

int main(int argc, char* argv[]) {

    vector<vector<int>> grid(3, vector<int>(3, 0));
    grid[1][0] = 1;
    //    grid[0][1] = 1;
    grid[1][1] = 1;

    for (const auto& vec : grid) {
        cout << vec << endl;
    }

    int ret = Solution().uniquePathsWithObstacles(grid);

    cout << "ret = " << ret;

    return 0;
}
