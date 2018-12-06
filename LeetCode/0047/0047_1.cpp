

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
using namespace std;

static auto fast = [](){
                       ios_base::sync_with_stdio(false);
                       cin.tie(nullptr);
                       return 0;
                   }();

// brute force, with optimization
void helper(vector<int>& nums, size_t pos, set<vector<int>>& ans) {
    if (pos >= nums.size()) {
        ans.insert(nums);
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
    set<vector<int>> ans;
    helper(nums, 0, ans);

    return vector<vector<int>>(ans.begin(), ans.end());
}


int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    vector<int> nums{-1,2,0,-1,1,0,1};

    auto ans = permuteUnique(nums);

    for (const auto& vec : ans) {
        for (int n : vec) {
            cout << n << " ";
        }
        cout << endl;
    }

    cout << ans.size() << endl;

    return 0;
}
