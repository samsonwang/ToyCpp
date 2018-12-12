
#include <vector>
#include <iostream>
#include <utility>

void bubble_sort(std::vector<int>& nums) {
    if (nums.size() < 2) {
        return;
    }

    for (size_t i = 0; i < nums.size()-1 ; ++i) {
        for (size_t j = 0; j+1+i < nums.size(); ++j) {
            if (nums[j] > nums[j+1]) {
                std::swap(nums[j], nums[j+1]);
            }
        }
    }
}

int main(int argc, char* argv[]) {

    std::vector<int> nums{5, 4, 3, 2, 1};

    bubble_sort(nums);

    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
