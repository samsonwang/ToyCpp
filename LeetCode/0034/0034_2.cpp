
#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    if(nums.empty()) return res;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    if (nums[right] != target) return res;
    res[0] = right;
    right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right= mid;
    }
    res[1] = left - 1;
    return res;
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
