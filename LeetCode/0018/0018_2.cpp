
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


// 仿照3sum的解法 在内层使用3sum解法
// 如何避免重复组合，这个是需要考虑的

vector<vector<int>> fourSum(vector<int>& nums, int target) {

    vector<vector<int>> ans;

    std::sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size();) {
        int n1 = nums[i];
        int target_1 = target - n1;

        for (size_t j=i+1; j<nums.size();) {
            int n2 = nums[j];
            int target_2 = target_1 - n2;

            int front = j+1;
            int end = nums.size()-1;
            while (front < end) {
                int n3 = nums[front];
                int sum = n3 + nums[end];
                if (sum == target_2) {
                    // 找到了
                    ans.push_back(vector<int> ({n1, n2, n3, nums[end]}));

                    do {
                        ++front;
                    } while(front<end && nums[front]==n3);
                }
                else if (sum > target_2) {
                    --end;
                }
                else {
                    ++front;
                }
            }

            do {
                ++j;
            } while (j<nums.size() && nums[j] == n2);
        }

        do {
            ++i;
        } while (i < nums.size() && nums[i] == n1);
    }

    return ans;
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
