
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

static auto fast = [] () {
                       ios::sync_with_stdio(false);
                       cin.tie(NULL);
                       return 0;
                   }();

// 这种算法的效率相对要高一些，但还是超时了
vector<vector<int>> threeSum(vector<int>& nums) {

    set<vector<int>> ans;

    for (size_t i=0; i<nums.size(); ++i) {
        int n1 = nums[i];

        // 在剩下的数中寻找相加之和为 -n1 的组合
        map<int, int> mapNum;

        for (size_t j=i+1; j<nums.size(); ++j) {
            int n2 = nums[j];
            int n3 = 0-n1-n2;
            if (mapNum[n3] > 0) {
                vector<int> triplet {n1, n2, n3};
                sort(triplet.begin(), triplet.end());
                ans.insert(triplet);
                // ans.push_back(vector<int>({n1, n2, n3}));
            }
            else {
                ++mapNum[n2];
            }
        }
    }

    vector<vector<int>> ret(ans.begin(), ans.end());
    return ret;
}

int main(int argc, char* argv[]) {

    vector<int> num1 {-1, 0, 1, 2, -1, -4};
    vector<int> num2 {0, 0, 0, 0};
    vector<int> num3 {14,4,6,-1,10,9,-8,7,-13,14,-13,-11,-8,-9,11,14,-8,-14,-13,7,-10,-15,-13,-11,-11,11,14,13,2,-14,1,-7,-2,14,-1,-15,9,7,-1,3,6,1,7,5,-1,-5,4,-2,-4,-1,-9,-7,-1,-7,-11,3,12,10,-7,-1,12,1,8,-13,1,14,9,-13,6,-7,-3,-11,2,-11,10,-14,-1,-9,0,2,5,6,3,-11,6,7,0,3,3,0,-12,-8,-13,3,-14,-5,2,10,-11,-14,-12,1,-10,5,5,7,-1,11,14,6,-10,-4,-3,8,-7,10,1,8,-1,-11,-15,-6,-12,-13,12,-11};

    auto ret = threeSum(num1);
    printf("ans count = %zi\n", ret.size());
    printf("--------------\n");

    for (size_t i=0; i<ret.size(); ++i) {
        vector<int>& triplet = ret[i];
        if (triplet.size() == 3) {
            printf("%d\t%d\t%d\n",
                   triplet[0], triplet[1], triplet[2]);
        }
    }

    printf("--------------\n");

    return 0;
}
