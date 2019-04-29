
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

// 每次堆化操作的时间复杂度为 log(k)
void heapify(std::vector<int>& nums, size_t i) {
    size_t largest = i;
    size_t l = 2*i + 1;
    size_t r = 2*i + 2;

    if (l < nums.size() && nums[l] > nums[largest]) {
        largest = l;
    }

    if (r < nums.size() && nums[r] > nums[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(nums[i], nums[largest]);

        heapify(nums, largest);
    }
}

void makeHeap(std::vector<int>& nums) {
    int len = (int)nums.size();
    for (int i=len/2-1; i>=0; --i) {
        heapify(nums, i);
    }
}

// 限定长度的堆化操作
void heapify(std::vector<int>& nums, size_t len, size_t i) {
    size_t largest = i;
    size_t l = i*2 + 1;
    size_t r = i*2 + 2;

    if (l < len && nums[l] > nums[largest]) {
        largest = l;
    }

    if (r < len && nums[r] > nums[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(nums[largest], nums[i]);

        heapify(nums, len, largest);
    }
}

// 仅使用数组中的前len个元素生成堆
void makeHeap(std::vector<int>& nums, size_t len) {
    // std::make_heap(nums.begin(), nums.begin()+len);

    for (int i=int(len)/2-1; i>=0 ; --i) {
        heapify(nums, len, i);
    }
}

void heapSort(std::vector<int>& nums) {
    //
    int pos = (int)nums.size();

    // 不断生成最大堆，找到余下的最大元素，
    // 将余下的最大元素放在有序部分的前端。
    while (pos > 0) {
        makeHeap(nums, pos);
        /*
          std::cout << "heapSort, pos:" << pos << std::endl;
          for (int n: nums) {
          std::cout << n << " ";
          }
          std::cout << std::endl;
        */

        std::swap(nums[0], nums[pos-1]);

        --pos;
    }
}

int main(int argc, char* argv[]) {

    //
    std::cout << "original nums" << std::endl;
    std::vector<int> nums({4, 3, 5, 6, 7, 8, 10, 9});

    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // C++11 中提供的将一个数组转化为堆的函数接口
    // std::make_heap(nums.begin(), nums.end());

    std::cout << "make heap" << std::endl;
    makeHeap(nums);

    for (int n : nums) {
        std::cout << n << " ";
    }

    std::cout << std::endl;


    std::cout << "heap sort" << std::endl;
    heapSort(nums);

    for (int n : nums) {
        std::cout << n << " ";
    }

    return 0;
}
