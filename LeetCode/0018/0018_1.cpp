
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 暴力解法
// 然后暴力解法竟然AC了
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> ans;

    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j=i+1; j < nums.size(); ++j) {
            for (size_t k=j+1; k < nums.size(); ++k) {
                for (size_t m=k+1; m < nums.size(); ++m) {
                    if (nums[i] + nums[j] + nums[k] + nums[m] == target) {
                        vector<int> t({nums[i], nums[j], nums[k], nums[m]});
                        sort(t.begin(), t.end());
                        ans.insert(t);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(ans.begin(), ans.end());
}

int main(int argc, char* argv[]) {
    vector<int> nums {1, 0, -1, 0, -2, 2};
    vector<int> nums2 {-3,-1,0,2,4,5};

    vector<vector<int>> ans = fourSum(nums2, 1);

    for (const auto& v : ans) {
        for (int n : v) {
            cout << n << "\t";
        }
        cout << endl;
    }

    return 0;
}
