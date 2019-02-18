
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
            int l = n - c;
            l = l > 0 ? l : 1;

            ++x;

            if (num > max) {
                break;
            }
            for (int i=0; i<l; ++i) {
                ans[y][x] = num;
                ++num;
                ++x;
            }

            if (num > max) {
                break;
            }
            for (int i=0; i<l; ++i) {
                ans[y][x] = num;
                ++num;
                ++y;
            }

            if (num > max) {
                break;
            }
            for (int i=0; i<l; ++i) {
                ans[y][x] = num;
                ++num;
                --x;
            }

            if (num > max) {
                break;
            }
            for (int i=0; i<l; ++i) {
                ans[y][x] = num;
                ++num;
                --y;
            }
            c += 2;
            ++y;
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {

    for (int i=3; i<6; ++i) {
        cout << "i=" << i << endl;
        vector<vector<int>> mat = Solution().generateMatrix(i);
        for (const auto& vec : mat) {
            cout << vec << endl;
        }
    }
    return 0;
}
