

#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

// 借助 leetcode 15 的解法

inline int getDiff (int t1, int t2) {
    if (t1 > t2) {
        return t1 - t2;
    }
    return t2 - t1;
}

int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) {
        return 0;
    }

    sort(nums.begin(), nums.end());

    int ans = nums[0] + nums[1] + nums[2];
    int diff = getDiff(ans, target);

    for (int i=0; i < nums.size(); ++i) {

        int n1 = nums[i];

        // 貌似这里计算的diff_t并没有用
        // 因为无法确定是正向偏移还是反向偏移
        // int diff_t = getDiff(n1, target);

        int front = i + 1;
        int end = nums.size() - 1;

        while (front < end) {
            int n2 = nums[front];
            int n3 = nums[end];
            int sum = n1 + n2 + n3;
            int diff_t = getDiff(sum, target);

            if (diff > diff_t) {
                ans = sum;
                diff = diff_t;
            }

            if (sum == target) {
                return sum;
            }
            else if (sum > target) {
                --end;
            }
            else {
                ++front;
            }
        }
    }

    return ans;
}

static const auto fast = []() {
                             std::ios_base::sync_with_stdio(false);
                             std::cin.tie(NULL);
                             return 0;
                         }();


int main(int argc, char* argv[]) {

    vector<int> nums1{-1, 2, 1, -4};
    vector<int> nums2{1, 1, 1, 0};
    int ans1 = threeSumClosest(nums1, 1);
    int ans2 = threeSumClosest(nums2, -100);
    printf("ans1 = %d\n", ans1);
    printf("ans2 = %d\n", ans2);


    return 0;
}
