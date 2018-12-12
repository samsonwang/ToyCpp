
#include <vector>
#include <iostream>
using namespace std;


int main(int argc, char* argv[]) {

    vector<int> nums1{1,2,3,4,5,6};

    // 只会拷贝d到 begin + 2 之前的元素
    vector<int> nums2(nums1.begin(), nums1.begin() + 2);

    for (int n : nums2) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
