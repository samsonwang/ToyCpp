
#include <vector>
using namespace std;

// method 3: recursive dfs
void dfs(vector<int> &num, vector<vector<int>> &ans) {
    if (num.size() == 1) {
        vector<int> tmp(num.begin(), num.end());
        ans.push_back(tmp);
        return;
    }

    vector<int> num1(num.begin()+1, num.end());
    dfs(num1, ans);

    vector<vector<int> > ans1;
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j <= ans[i].size(); ++j) {
            vector<int> tmp = ans[i];
            tmp.insert(tmp.begin()+j, num[0]);
            ans1.push_back(tmp);
        }
    }

    ans = ans1;
}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ans;
    dfs(num, ans);
    return ans;
}

int main(int argc, char* argv[]) {

    vector<int> nums{1, 2, 3};
    auto ans = permute(nums);


    return 0;
}

// dfs的方法，我对这种思路还不是很熟，需要多加练习
