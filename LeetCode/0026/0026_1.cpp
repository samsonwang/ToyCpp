
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    size_t left = 0;
    size_t right = 1;

    for (; right<nums.size(); ++right) {
        if (nums[left] != nums[right]) {
            ++left;
            nums[left] = nums[right];
        }
    }

    return left+1;
}

void print(const vector<int>& vecNums) {
    for (int n : vecNums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {

    vector<int> nums{1, 2, 3, 4, 5, 6, 7};

    print(nums);

    int ret = removeDuplicates(nums);

    print(nums);

    std::cout << ret << std::endl;

    return 0;
}
