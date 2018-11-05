
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// 可以重复使用备选元素
//

// dp方法在使用map作为记录的数据结构时，不好控制，由于map会不断变化，所以不容易到达map的结尾
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());

    map<int, set<vector<int>>> dp;

    for (int n : candidates) {
        vector<int> combi{n};
        dp[n].insert(combi);
    }


    for (size_t i=0; i<candidates.size(); ++i) {
        for (auto it=dp.begin(); it != dp.end(); ++it) {
            int index_o = it->first;
            int index_n = index_o + candidates[i];

            set<vector<int>>& combi_o = dp[index_o];
            set<vector<int>>& combi_n = dp[index_n];

            for (auto combi : combi_o) {
                combi.push_back(candidates[i]);
                combi_n.insert(combi);
            }
        }
    }


    // dp print out
    for (const auto& kvp : dp) {
        int k = kvp.first;
        const set<vector<int>>& v = kvp.second;
        for (const auto& combi : v) {
            cout << k << ": ";
            for (int n : combi) {
                cout << n << " ";
            }
            cout << endl;
        }
    }

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
