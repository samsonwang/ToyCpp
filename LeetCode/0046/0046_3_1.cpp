

#include <vector>
#include <iostream>
using namespace std;

void helper(vector<int>& nums, size_t pos, vector<vector<int>>& ans) {
    if (pos >= nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (size_t i=pos; i<nums.size(); ++i) {
        swap(nums[pos], nums[i]);
        helper(nums, pos+1, ans);
        swap(nums[pos], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    helper(nums, 0, ans);
    return ans;
}

int main(int argc, char* argv[]) {

    vector<int> nums{1, 2, 3};

    auto ans = permute(nums);

    for (const auto& vec : ans) {
        for (int n : vec) {
            cout << n << " ";
        }
        cout << endl;
    }



    return 0;
}
