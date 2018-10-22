
#include <vector>
#include <iostream>
#include <unistd.h>
using namespace std;

// standard binary search algorithm
int binarySearch(const vector<int>& nums, int target, int left, int right) {
    if (nums[left] <= nums[right]) { // ascend
        while (left <= right) {
            int mid = (left+right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
    }
    else { // descend
        while (left <= right) {
            int mid = (left+right) / 2;
            if (nums[mid] < target) {
                right = mid - 1;
            }
            else if (nums[mid] > target) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
    }
    return -1;
}

int searchHelper(const vector<int>& nums, int target, int left, int right) {
    sleep(1);
    cout << "** left:" << left << " right: " << right << endl;
    int front = nums[left];
    int back = nums[right];
    int mid = nums[(left+right)/2];

    if ((front <= mid && mid <= back)
        || (front >= mid && mid >= back)) {
        cout << "** standard binary search("
             << left << ", " << right << ")" << endl;
        return binarySearch(nums, target, left, right);
    }

    int posMid = (left + right) / 2;
    cout << "** posMid: " << posMid << endl;

    int ans1 = searchHelper(nums, target, left, posMid);
    if (ans1 != -1) {
        return ans1;
    }

    int ans2 = searchHelper(nums, target, posMid, right);
    if (ans2 != -1) {
        return ans2;
    }
    return -1;
}

// 由于题目中限定了算法的时间复杂度
int search(vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }

    return searchHelper(nums, target, 0, nums.size()-1);
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
