

/*
  https://leetcode.com/problems/unique-paths-ii/discuss/23248/My-C%2B%2B-Dp-solution-very-simple!
  技巧：
  1. 将dp的空间多申请了一圈，这样就巧妙地将边界条件问题避开了
  2. 在进行dp求解的过程中，只需要判断斜上方是否有障碍就可以了
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};
