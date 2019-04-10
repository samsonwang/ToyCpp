
#include <vector>
#include <iostream>
#include <list>
#include "../../shared/stream.h"

using namespace std;

// 使用穷举法
// 列举出所有的可能路径，对于每个路径计算出该路径的取值
// 需要使用BFS的思想

// leetcode 给出的结果是超时

// 在BFS时针对值做优化，以减少list中元素的个数

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t m = grid.size();
        if (m == 0) {
            return 0;
        }
        size_t n = grid.front().size();

        int minSum = -1;
        list<PosVal> bfs;
        bfs.push_back(PosVal({0, 0, grid[0][0]}));

        while (!bfs.empty()) {
            PosVal pv = bfs.front();
            bfs.pop_front();

            if (minSum != -1 && pv.val > minSum) {
                continue;
            }

            // 已经运行到终点
            if (pv.x == m-1 && pv.y == n-1) {
                if (minSum == -1) {
                    minSum = pv.val;
                }
                else if (minSum > pv.val) {
                    minSum = pv.val;
                }
                continue;
            }

            // down
            if (pv.x < m - 1) {
                int val = pv.val + grid[pv.x+1][pv.y];
                if (minSum == -1 || minSum < val) {
                    bfs.push_back(PosVal({pv.x+1, pv.y, val}));
                }
            }

            // right
            if (pv.y < n - 1) {
                int val = pv.val + grid[pv.x][pv.y+1];
                if (minSum == -1 || minSum < val) {
                    bfs.push_back(PosVal({pv.x, pv.y+1, val}));
                }
            }
        }

        //        PosVal t = bfs.front();
        //        cout << t.x << t.y << t.val << endl;

        return minSum;
    }

private:
    struct PosVal {
        size_t x;
        size_t y;
        int val;

        /*
          PosVal(size_t x_, size_t y_, int val_)
          : x(x_), y(y_), val(val_) {

          }
        */
    };
};

int main(int argc, char* argv[]) {
    vector<vector<int>> grid;
    grid.push_back(vector<int>({1, 3, 1}));
    grid.push_back(vector<int>({1, 5, 1}));
    grid.push_back(vector<int>({4, 2, 1}));

    for (const auto& row : grid) {
        cout << row << endl;
    }
    int ret = Solution().minPathSum(grid);
    cout << "ret = " << ret << endl;

    return 0;
}
