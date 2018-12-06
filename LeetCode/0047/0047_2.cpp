

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
using namespace std;

// wrong answer
void helper(vector<int>& nums, size_t pos, vector<vector<int>>& ans) {
    if (pos >= nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (size_t i=pos; i<nums.size(); ++i) {
        if (pos != i && nums[pos] == nums[i]) {
            continue;
        }
        swap(nums[pos], nums[i]);
        helper(nums, pos+1, ans);
        swap(nums[pos], nums[i]);

        while (i+1 < nums.size()
               && nums[i+1] == nums[i]) {
            ++i;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    helper(nums, 0, ans);
    return ans;
}

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    vector<int> nums{-1,2,0,-1,1,0,1};

    auto ans = permuteUnique(nums);

    sort(ans.begin(), ans.end());
    auto last = unique(ans.begin(), ans.end());
    for (auto it = last; it != ans.end(); ++it) {
        auto& combi = *it;
        if (combi.empty()) {
            continue;
        }
        for (int n : combi) {
            cout << n << " ";
        }
        cout << endl;
    }
    cout << ans.end() - last << endl;



/*
  for (const auto& vec : ans) {
  for (int n : vec) {
  cout << n << " ";
  }
  cout << endl;
  }

  cout << ans.size() << endl;
*/
    return 0;
}
