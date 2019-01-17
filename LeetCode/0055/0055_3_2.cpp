
#include <vector>
#include <iostream>

#include "../../shared/stream.h"

bool canJump(const std::vector<int>& nums) {
    int lastGood = nums.size() - 1;
    for (int i = lastGood; i >= 0; --i) {
        if (i + nums[i] >= lastGood) {
            lastGood = i;
        }
    }
    return lastGood == 0;
}

void printVec(const std::vector<int>& nums) {
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::vector<int> nums_1{2,3,1,1,4};
    std::cout << nums_1 << std::endl;
    bool ret_1 = canJump(nums_1);
    printVec(nums_1);
    std::cout << ret_1 << std::endl;
    std::cout << "--- " << std::endl;

    std::vector<int> nums_2{3,2,1,0,4};
    bool ret_2 = canJump(nums_2);
    printVec(nums_2);
    std::cout << ret_2 << std::endl;
    std::cout << "--- " << std::endl;

    std::vector<int> nums_3{0};
    bool ret_3 = canJump(nums_3);
    printVec(nums_3);
    std::cout << ret_3 << std::endl;
    std::cout << "--- " << std::endl;

    std::vector<int> nums_4{2,0,0};
    bool ret_4 = canJump(nums_4);
    printVec(nums_4);
    std::cout << ret_4 << std::endl;
    std::cout << "--- " << std::endl;

    return 0;
}
