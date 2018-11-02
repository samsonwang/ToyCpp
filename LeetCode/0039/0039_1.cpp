
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
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
