
#include <vector>
#include <iostream>
using namespace std;


/*
  使用了回溯算法的思想，在leetcode最终卡在最后一个testcase上，失败的原因是超时，难道还
  有比回溯算法速度更快的思路么？

  回溯算法的时间复杂度是什么？是如何推倒计算出来的？

*/

static auto fast = [](){
                       ios_base::sync_with_stdio(false);
                       cin.tie(nullptr);
                       return 0;
                   }();

bool jump(const vector<int>& nums, size_t pos) {
    if (pos >= nums.size()-1) {
        return true;
    }

    int step = nums[pos];

    bool ret = false;
    for (int i=step; i>0; --i) {
        ret |= jump(nums, pos+i);
        if (ret) {
            break;
        }
    }

    return ret;
}

bool canJump(vector<int>& nums) {
    return jump(nums, 0);
}

void printVec(const vector<int>& nums) {
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums_1{2,3,1,1,4};
    vector<int> nums_2{3,2,1,0,4};
    vector<int> nums_3{0};
    vector<int> nums_4{2,0,0};

    bool ret_1 = canJump(nums_1);
    bool ret_2 = canJump(nums_2);
    bool ret_3 = canJump(nums_3);
    bool ret_4 = canJump(nums_4);

    printVec(nums_1);
    cout << ret_1 << endl;
    cout << "--- " << endl;

    printVec(nums_2);
    cout << ret_2 << endl;
    cout << "--- " << endl;

    printVec(nums_3);
    cout << ret_3 << endl;
    cout << "--- " << endl;

    printVec(nums_4);
    cout << ret_4 << endl;
    cout << "--- " << endl;

    return 0;
}
