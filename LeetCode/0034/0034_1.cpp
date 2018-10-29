
#include <vector>
#include <iostream>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans{-1, -1};
    if (nums.empty()) {
        return ans;
    }
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
        else {
            int leftInnerL = left;
            int leftInnerR = mid;
            while (leftInnerL <= leftInnerR) {
                int leftInnerM = (leftInnerL + leftInnerR) / 2;
                if (nums[leftInnerM] < target) {
                    leftInnerL = leftInnerM + 1;
                }
                else {
                    leftInnerR = leftInnerM - 1;
                }
            }
            ans[0] = leftInnerL;
            int rightInnerL = mid;
            int rightInnerR = right;
            while (rightInnerL <= rightInnerR) {
                int rightInnerM = (rightInnerL + rightInnerR) / 2;
                if (nums[rightInnerM] > target) {
                    rightInnerR = rightInnerM - 1;
                }
                else {
                    rightInnerL = rightInnerM + 1;
                }
            }
            ans[1] = rightInnerR;
            return ans;
        }
    }
    return ans;
}

int main(int argc, char* argv[]) {

    vector<int> nums{5,7,7,8,8,10};
    int target = 10;

    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;
    cout << "target: " << target << endl;

    vector<int> ans = searchRange(nums, target);

    for (int n : ans) {
        cout << n << " ";
    }
    cout <<  endl;

    return 0;
}
