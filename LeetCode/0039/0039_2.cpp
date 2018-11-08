
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <list>

using namespace std;

// 可以重复使用备选元素
// 结果中不能包含重复的组合

// 尝试使用暴力解法求解

bool sumEqual(vector<int>& nums, int target) {
    for (int n : nums) {
        target -= n;
        if (target < 0) {
            return false;
        }
    }
    return target == 0;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    set<vector<int>> ans;
    sort(candidates.begin(), candidates.end());

    // 将所有可能的组合都列举出来
    bool f = target%candidates.front() == 0;
    int lenMax = target/candidates.front() + (f ? 0 : 1); // 可能的最大长度

    cout << "lenmax:" << lenMax << endl;

    list<vector<int>> bfs;
    bfs.push_back(vector<int>());
    while(!bfs.empty()) {
        vector<int> temp = bfs.front();
        bfs.pop_front();
        if (temp.size() >= size_t(lenMax)) {
            if (sumEqual(temp, target)) {
                ans.insert(temp);
            }
            continue;
        }
        for (int n : candidates) {
            if (!temp.empty() && temp.back() > n) {
                if (sumEqual(temp, target)) {
                    ans.insert(temp);
                }
                continue;
            }
            temp.push_back(n);
            bfs.push_back(temp);
            temp.pop_back();
        }
    }

    return vector<vector<int>>(ans.begin(), ans.end());
}

int main(int argc, char* argv[]) {

    vector<int> candidates{2,3,5};
    int target = 8;

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

    cout << "ans size():" << ans.size();

    return 0;
}
