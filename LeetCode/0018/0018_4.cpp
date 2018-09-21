
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

static const auto fast = [](){
                             ios_base::sync_with_stdio(false);
                             cin.tie(nullptr);
                             return 0;
                         }();



vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> total;
    int n = nums.size();
    if(n < 4) return total;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n - 3; i++)
    {
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
            break;
        if(nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target)
            continue;
        for(int j = i + 1; j < n - 2; j++)
        {
            if(j > i + 1 && nums[j] == nums[j-1])
                continue;
            if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)
                break;
            if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target)
                continue;
            int l = j + 1, r = n - 1;
            while(l < r)
            {
                int sum = nums[i] + nums[j] + nums[l] + nums[r];
                if(sum < target)
                    l++;
                else if(sum > target)
                    r--;
                else
                {
                    total.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                    do{l++;}while(nums[l] == nums[l-1] && l < r);
                    do{r--;}while(nums[r] == nums[r+1] && l < r);
                }
            }
        }
    }
    return total;
}

int main(int argc, char* argv[]) {
    vector<int> nums {1,0,-1,0,-2,2};
    vector<int> nums2 {-3,-1,0,2,4,5};

    vector<vector<int>> ans = fourSum(nums, 0);

    for (const auto& v : ans) {
        for (int n : v) {
            cout << n << "\t";
        }
        cout << endl;
    }

    return 0;
}
