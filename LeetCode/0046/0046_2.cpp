
#include <vector>
#include <list>
#include <iostream>
using namespace std;



// !! false appraoch
void helper(vector<int>& nums, vector<vector<int>>& ans) {

    vector<int> combi;
    for (size_t i=0; i<nums.size(); ++i) {



    }


}

// backtrace like approach
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.empty()) {
        return ans;
    }

    list<list<int>> temp;
    temp.push_back(list<int>(1, nums[0]));
    while (!temp.empty()) {
        list<int> combi = temp.front();
        temp.pop_front();
        size_t s = combi.size();
        if (s == nums.size()) {
            ans.push_back(vector<int>(combi.begin(), combi.end()));
            continue;
        }
        int n = nums[s];
        for (auto it=combi.begin(); it != combi.end(); ++it) {
            it = combi.insert(it, n);
            temp.push_back(combi);
            it = combi.erase(it);
        }
        combi.push_back(n);
        temp.push_back(combi);
    }
    return ans;
}


int main(int argc, char* argv[]) {

    vector<int> nums{1, 3, 2};
    auto ans = permute(nums);

    cout << "ans size:" << ans.size() << endl;
    for (const auto& v : ans) {
        for (int n : v) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
