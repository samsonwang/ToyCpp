
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// 可以重复使用备选元素
// 结果中不能包含重复的组合

// 尝试使用递归方法
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());

    return ans;
}

int main(int argc, char* argv[]) {

    vector<int> candidates{2,3,6,7};
    int target = 7;

    for (int n : candidates) {
        cout << n << " ";
    }

    cout << endl << target << endl;

    vector<vector<int>> ans = combinationSum(candidates, target);

    for (const auto& combi : ans) {
        for (int n : combi) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
