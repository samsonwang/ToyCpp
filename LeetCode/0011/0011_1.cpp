
/*
  Input: [1,8,6,2,5,4,8,3,7]
  Output: 49
*/


/*
  最容易想到的就是暴力解法了
*/


#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int maxArea(vector<int>& height) {
    int ans = 0;

    int len = height.size();

    for (int i=0; i < len-1; ++i) {
        for (int j=i+1; j < len; ++j) {
            int size = (j-i) * min(height[i], height[j]);
            ans = ans > size ? ans : size;
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
