/*
  greedy
  贪心算法
*/

#include <vector>
#include <iostream>
using namespace std;

bool canJump(vector<int>& nums) {
    int lastPos = nums.size() - 1;

    for (int i = nums.size()-1; i >= 0; --i) {
        if (i + nums[i] >= lastPos) {
            lastPos = i;
        }
    }
    return lastPos == 0;
}

void printVec(const vector<int>& nums) {
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums_1{2,3,1,1,4};
    bool ret_1 = canJump(nums_1);
    printVec(nums_1);
    cout << ret_1 << endl;
    cout << "--- " << endl;

    vector<int> nums_2{3,2,1,0,4};
    bool ret_2 = canJump(nums_2);
    printVec(nums_2);
    cout << ret_2 << endl;
    cout << "--- " << endl;

    vector<int> nums_3{0};
    bool ret_3 = canJump(nums_3);
    printVec(nums_3);
    cout << ret_3 << endl;
    cout << "--- " << endl;

    vector<int> nums_4{2,0,0};
    bool ret_4 = canJump(nums_4);
    printVec(nums_4);
    cout << ret_4 << endl;
    cout << "--- " << endl;

    return 0;
}
