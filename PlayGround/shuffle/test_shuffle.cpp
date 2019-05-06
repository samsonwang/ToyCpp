

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

void shuffle(std::vector<int>& nums) {
    srand(time(0));

    for (size_t i=0; i<nums.size()-2; ++i) {
        int r = i + (rand() % (nums.size()-i));
        std::swap(nums[i], nums[r]);
    }
}


int main(int argc, char* argv[]) {
    std::vector<int> nums;

    for (size_t i=1; i<=10; ++i) {
        nums.push_back(i);
    }

    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    shuffle(nums);

    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
