
#include <vector>
#include <iostream>
#include "../../shared/stream.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for (int i=0; i<n; ++i) {
            ans.emplace_back(n, 0);
        }

        int x = -1;
        int y = 0;
        int num = 1;
        int max = n * n;
        int c = 1;

        while (true) {
            ++x;

            if (num > max) {
                break;
            }
            for (int i=c; i<n; ++i) {
                ans[y][x] = num;
                ++num;
                ++x;
            }

            if (num > max) {
                break;
            }
            for (int i=c; i<n; ++i) {
                ans[y][x] = num;
                ++num;
                ++y;
            }

            if (num > max) {
                break;
            }
            for (int i=c; i<n; ++i) {
                ans[y][x] = num;
                ++num;
                --x;
            }

            if (num > max) {
                break;
            }
            for (int i=c; i<n; ++i) {
                ans[y][x] = num;
                ++num;
                --y;
            }
            ++c;
            ++y;
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> mat = Solution().generateMatrix(5);
    for (const auto& vec : mat) {
        cout << vec << endl;
    }
    return 0;
}
