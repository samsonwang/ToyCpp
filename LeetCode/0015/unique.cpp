
// 编写一个std::unique类似的函数
#include <vector>
#include <iostream>
#include <algorithm>

size_t unique(std::vector<int>& nums, size_t begin, size_t end) {
    if (begin == end) {
        return end;
    }

    size_t ret = begin;
    while (++begin != end) {
        if (!(nums[ret] == nums[begin]) && ++ret != begin) {
            nums[ret] = nums[begin];
        }
    }

    return ++ret;
}

// 易懂的版本 concise version
size_t unique2(std::vector<int>& nums) {
    size_t begin = 0;
    size_t end = nums.size();

    size_t ret = begin;
    ++begin;

    while (begin != end) {
        if (nums[begin] != nums[ret]
            && ret+1 != begin) { // 这一行的判断是为了避免出现自己给自己赋值的情况

            nums[ret+1] = nums[begin];
            ++begin;
            ++ret;
        }
        else {
            ++begin;
        }
    }

    return ++ret;
}

typedef std::vector<int>::iterator ForwardIt;
ForwardIt unique(ForwardIt first, ForwardIt last) {
    if (first == last)
        return last;

    ForwardIt result = first;
    while (++first != last) {
        if (!(*result == *first) && ++result != first) {
            *result = std::move(*first);
        }
    }

    return ++result;
}

int main(int argc, char* argv[]) {

    std::vector<int> nums{1,2,3,1,2,3,3,4,5,4,5,6,7};
    std::sort(nums.begin(), nums.end());

    // unique(nums, 0, nums.size());
    // unique(nums.begin(), nums.end());

    std::vector<int> nums2 {1, 2, 2, 3, 3, 4, 5};
    size_t ret = unique2(nums2);
    std::cout << "ans=" << ret  << "\n";

    for (int i : nums2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
