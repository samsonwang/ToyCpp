
#include <vector>
#include <iostream>

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

// !!!! 这个是错误的答案
void nextPermutation(vector<int>& nums) {

    int bigger = -1;
    for (int i=nums.size()-1; i > 0; --i) {
        if (nums[i] > nums[i-1]) {
            // 找到了较大数的位置
            bigger = i;
            break;
        }
    }

    cout << "bigger: " << bigger << endl;

    if (bigger<0) {
        // 数组翻转
        reverse(nums);
        return;
    }

    // 再为这个较大的数找到合适的位置
    int smaller = -1;
    for (int i=bigger-1; i>0; --i) {
        if (nums[i] < nums[bigger]) {
            smaller = i;
            break;
        }
    }

    cout << "smaller: " << smaller << endl;

    if (smaller < 0) {
        reverse(nums);
        return;
    }

    int temp = nums[bigger];
    nums[bigger] = nums[smaller];
    nums[smaller] = temp;
}

int main(int argc, char* argv[]) {

    vector<int> nums{1, 3, 2};

    nextPermutation(nums);

    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
