
/*
  https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
  使用dp方法，这篇文章逐步推进，展现了对内存空间使用的优化思路
*/

// 普通dp方法
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

// 由于在每次计算时，只需要用到本行和前一行中的数据
// 所以可以将空间复杂度降低为 O(n)
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n, 1), cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] = pre[j] + cur[j - 1];
            }
            swap(pre, cur);
        }
        return pre[n - 1];
    }
};

// 重新检查代码，能够发现 pre[j] 是 cur[j] 更新之前的数据，
// 所以就可以简化为使用一行空间
class Solution3 {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
    }
};
