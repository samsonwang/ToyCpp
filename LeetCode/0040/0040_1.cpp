
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 与combination sum 1 相似，这里限制了candidate在组合中出现的次数
// 我在想可以使用bfs方法进行求解
// 也可以通过限制backtracing的条件完成求解


void helper(vector<int>& candidates, int target,
            vector<vector<int>>& ans, vector<int>& combi, int sum, size_t pos) {
    if (sum > target) {
        return;
    }
    else if (sum == target) {
        ans.push_back(combi);
        return;
    }

    for (size_t i=pos; i<candidates.size(); ++i) {
        if (candidates[i] > target) {
            return;
        }

        combi.push_back(candidates[i]);
        helper(candidates, target, ans, combi, sum+candidates[i], i+1);
        combi.pop_back();

        while (i+1 < candidates.size()
               && candidates[i] == candidates[i+1]) {
            ++i;
        }
    }

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> combi;

    helper(candidates, target, ans, combi, 0, 0);
    return ans;
}

int main(int argc, char* argv[]) {
/*
  vector<int> candidates{10,1,2,2,7,6,1,5};
  int target = 8;
*/
    vector<int> candidates{2,2,2};
    int target = 2;

    vector<vector<int>> ans = combinationSum2(candidates, target);

    for (const auto& combi : ans) {
        for (int num : combi) {
            cout << num << " ";
        }
        cout << endl;
    }


    return 0;
}
