
#include <vector>
#include <iostream>
#include <unistd.h>
using namespace std;

// leetcode fastest sample
int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = (high - low)/2 + low;
        if (target == nums[mid]) return mid;
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target and target <= nums[mid])
                high = mid - 1;
            else low = mid + 1;
        }
        else {
            if (nums[mid] <= target and target <= nums[high])
                low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    //    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    vector<int> nums{3, 1};
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;
    int target = 1;
    cout << "target: " << target << endl;
    int ans = search(nums, target);
    cout << "ans: " << ans << endl;
    return 0;
}
