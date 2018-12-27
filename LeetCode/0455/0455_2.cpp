
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int any = []() {
              ios::sync_with_stdio(false);
              cin.tie(nullptr);
              return 0;
          }();

// leetcode fastest sample
int findContentChildren(vector<int> &g, vector<int> &s) {
    int count = 0;
    make_heap(g.begin(), g.end());
    sort_heap(g.begin(), g.end());
    make_heap(s.begin(), s.end());
    sort_heap(s.begin(), s.end());
    for (size_t i = 0, j = 0; i < g.size() && j < s.size(); ++j) {
        count += s[j] >= g[i];
        i += s[j] >= g[i];
    }
    return count;
}

int main(int argc, char* argv[]) {

    vector<int> g1{1,2,3};
    vector<int> s1{1,1,1};

    int ans = findContentChildren(g1, s1);

    cout << "ans: " << ans << endl;

    return 0;
}
