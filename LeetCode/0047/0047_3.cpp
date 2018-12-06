
#include <vector>
#include <iostream>
using namespace std;

// leetcode solution
void permute(vector<int> &n, int b, vector<vector<int> > &res){
    if(b == n.size()){
        res.push_back(n);
        return;
    }

    for(int i = b; i < n.size(); ++i){
        bool doSwap = true;
        for(int j = b; j < i; ++j){
            if(n[j] == n[i]){
                doSwap = false;
                break;
            }
        }

        if(doSwap){
            swap(n[i],n[b]);
            permute(n,b + 1,res);
            swap(n[i],n[b]);
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(begin(nums),end(nums));
    vector<vector<int> > result;
    permute(nums,0,result);
    return result;
}


int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    vector<int> nums{-1,2,0,-1,1,0,1};

    auto ans = permuteUnique(nums);

    sort(ans.begin(), ans.end());
    auto last = unique(ans.begin(), ans.end());
    for (auto it = last; it != ans.end(); ++it) {
        auto& combi = *it;
        if (combi.empty()) {
            continue;
        }
        for (int n : combi) {
            cout << n << " ";
        }
        cout << endl;
    }
    cout << ans.end() - last << endl;



/*
  for (const auto& vec : ans) {
  for (int n : vec) {
  cout << n << " ";
  }
  cout << endl;
  }

  cout << ans.size() << endl;
*/
    return 0;
}
