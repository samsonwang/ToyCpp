
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

// 暴力解法
int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) {
        return 0;
    }

    int ans = nums[0] + nums[1] + nums[2];
    int diff = abs(target - ans);

    // 穷举出所有的组合，与target比较，找到最接近的
    for (int i=0; i < nums.size(); ++i) {
        for (int j=i+1; j < nums.size(); ++j) {
            for (int k=j+1; k < nums.size(); ++k) {
                int sum_t = nums[i] + nums[j] + nums[k];
                int diff_t = abs(target - sum_t);

                ans = diff_t < diff ? (diff = diff_t, sum_t) : ans;

                if (ans == target) {
                    return ans;
                }
            }
        }
    }

    return ans;
}

int main(int argc, char* argv[]) {

    vector<int> nums1{-1, 2, 1, -4};
    vector<int> nums2{1, 1, 1, 0};
    int ans1 = threeSumClosest(nums1, 1);
    int ans2 = threeSumClosest(nums2, -100);
    printf("ans1 = %d\n", ans1);
    printf("ans2 = %d\n", ans2);


    return 0;
}
