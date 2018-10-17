
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void reverse(vector<int>& nums) {
    cout << "reversed" << endl;

    int front = 0;
    int end = nums.size() - 1;

    while (front < end) {
        int t = nums[front];
        nums[front] = nums[end];
        nums[end] = t;
        ++front;
        --end;
    }
}

void nextPermutation(vector<int>& nums) {
    // travel from left to right， find a smaller one than left base
    // get the lowest digit that can swap
    // sort after swap

    int left = -1;
    int right = -1;
    for (int i = 0; i < nums.size(); ++i) {
        int right_t = i+1;
        bool matched = false;
        for (int j = i+1; j < nums.size(); ++j) {
            if (nums[j] > nums[i]
                && nums[j] <= nums[right_t]) {
                right_t = j;
                matched = true;
            }
        }

        if (matched) {
            left = i;
            right = right_t;
        }
    }

    cout << "left:  " << left << endl;
    cout << "right: " << right << endl;

    if (left < 0 || right < 0) {
        reverse(nums);
        return;
    }

    // swap
    int t = nums[left];
    nums[left] = nums[right];
    nums[right] = t;

    // left+1, right
    if (left+1 < nums.size()) {
        sort(nums.begin()+left+1,
             nums.end());
    }
}

int main(int argc, char* argv[]) {

    vector<int> nums{1, 2, 3};
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    nextPermutation(nums);

    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
