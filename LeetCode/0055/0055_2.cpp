
#include <vector>
#include <iostream>
using namespace std;

/*
  使用动态规划的方法
*/

static auto fast = [](){
                       ios_base::sync_with_stdio(false);
                       cin.tie(nullptr);
                       return 0;
                   }();

bool canJump(vector<int>& nums) {
    if (nums.size() < 2) {
        return true;
    }

    vector<bool> dpJump(nums.size(), false);
    size_t size = dpJump.size();

    dpJump[size - 1] = true;

    for (int i=size-2; i>=0; --i) {
        int step = nums[i];
        if ((size_t)step + i >= size-1) {
            dpJump[i] = true;
        }
        else {
            bool jmp = false;
            for (int j=step+i; j>0; --j) {
                jmp |= dpJump[j];
                if (jmp) {
                    break;
                }
            }
            dpJump[i] = jmp;
        }
    }

    return dpJump[0];
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
