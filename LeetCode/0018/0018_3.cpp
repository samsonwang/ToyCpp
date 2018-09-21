
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

static const auto fast = [](){
                             ios_base::sync_with_stdio(false);
                             cin.tie(nullptr);
                             return 0;
                         }();

// 下面这个是leetcode上的解法，运行速度很快

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) return res;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for (int i = 0; i < len-3; i++) {
        //avoid duplicate
        if (i > 0 && nums[i] == nums[i-1]) continue;
        // if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
        // if (nums[i] + nums[len-3] + nums[len-2] + nums[len-1] < target) continue;
        //version3: less tight pruning
        if (4 * nums[i] > target) break;
        if (nums[i] +  3 * nums[len-1] < target) continue;
        for (int j = i+1; j < len-2; ++j) {
            if (j > i+1 && nums[j] == nums[j-1]) continue;
            // if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
            // if (nums[i] + nums[j] + nums[len-2] + nums[len-1] < target) continue;
            //version3: less tight pruning
            if (nums[i] + 3* nums[j] > target) break;
            if (nums[i] + nums[j] + 2 * nums[len-1] < target) continue;
            //now the problems becomes 3 sum problem and only two other elements only to be considered
            int left  = j+1, right = len-1;
            int sofar = nums[i] + nums[j];
            while (left < right) {
                if (sofar + nums[left] + nums[right] == target) {
                    res.push_back(vector<int>({nums[i], nums[j], nums[left], nums[right]}));
                    //how to skip the duplicate left and right
                    //version1: my own version
                    //  left++;
                    //  right--;
                    //  while (left < right && nums[left-1] == nums[left])  ++left;
                    // while (right > left && nums[right+1] == nums[right]) --right;
                    //version2: refer others
                    do{left++;} while (left < right && nums[left] == nums[left-1]);
                    do{right--;} while (right > left && nums[right] == nums[right+1]);
                }
                else if (sofar + nums[left] + nums[right] < target) left++;
                else right--;
            }
        }
    }
    return res;
}
//     struct vector_hash {
//     size_t operator()(const std::vector<int>& v) const {
//         std::hash<int> hasher;
//         size_t seed = 0;
//         for (int i : v) {
//             seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
//         }
//         return seed;
//     }
// };
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> res;
//         if (nums.size() <= 3) return res;
//         sort(nums.begin(), nums.end());
//         unordered_map<long, vector<pair<int, int>>> om;
//         for (int i = 0; i < nums.size(); i++)
//             for (int j = i+1; j < nums.size(); j++) {
//                 auto vp  = make_pair(i,j);
//                 auto it  = om.find(nums[i] + nums[j]);
//                 if (it != om.end())
//                 it->second.push_back(vp);
//                 else {
//                     vector<pair<int, int>> vt;
//                     vt.push_back(vp);
//                     om.insert({nums[i] + nums[j], vt});
//                 }

//             }
//         unordered_set<vector<int>, vector_hash> s;
//         for (const auto & entry : om) {
//             long cur = entry.first;
//             long rem = target - cur;
//             if (om.find(rem) != om.end()) {
//                 auto it = om.find(rem);
//                 for (const auto & e : entry.second)
//                 for (const auto & v : it->second) {
//                     vector<int> tmp = {e.first, e.second, v.first, v.second};// sort the rank
//                     sort(tmp.begin(), tmp.end());
//                     if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[2] == tmp[3]) continue;
//                     vector<int> newvec = {nums[tmp[0]], nums[tmp[1]], nums[tmp[2]], nums[tmp[3]]};
//                     s.insert(newvec);
//                 }
//             }
//         }
//      vector<vector<int>> v(s.begin(), s.end());
//      return v;
//     }

int main(int argc, char* argv[]) {
    vector<int> nums {1,0,-1,0,-2,2};
    vector<int> nums2 {-3,-1,0,2,4,5};

    vector<vector<int>> ans = fourSum(nums, 0);

    for (const auto& v : ans) {
        for (int n : v) {
            cout << n << "\t";
        }
        cout << endl;
    }

    return 0;
}
