
/*
  Input: [1,8,6,2,5,4,8,3,7]
  Output: 49
*/

/*
  这个方法是从leetcode上看来的，以至于为什么这个是正确的，还需要更深层的考虑
  论证这个方法正确的完成步骤
*/

#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {

    int ans = 0;
    int left = 0;
    int right = height.size()-1;

    while (left < right) {
        int w = right - left;
        int h = min(height[left], height[right]);

        ans = max(w*h, ans);

        if (height[left] < height[right]) {
            ++left;
        }
        else {
            --right;
        }
    }

    return ans;
}

int main(int argc, char* argv[])
{
    // 只有在C++11中支持这种写法
    vector<int> val1 {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int ans1 = maxArea(val1);

    printf("ans1 = %d\n", ans1);

    return 0;
}
