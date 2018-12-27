
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int ans = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    size_t gi = 0;
    size_t si = 0;
    while (si<s.size() && gi<g.size()) {
        if (s[si] >= g[gi]) {
            ++ans;
            ++si;
            ++gi;
        }
        else {
            ++si;
        }
    }

    return ans;
}

int main(int argc, char* argv[]) {

    vector<int> g1{1,2,3};
    vector<int> s1{1,1,1};

    int ans = findContentChildren(g1, s1);

    cout << "ans: " << ans << endl;

    return 0;
}
