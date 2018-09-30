
#include <vector>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

static const auto fast = [](){
                             ios_base::sync_with_stdio(false);
                             cin.tie(NULL);
                             return 0;
                         }();

// 使用递归

// n=4   (())(())   造不出来，

vector<string> generateParenthesis(int n) {
    if (n == 1) {
        return vector<string>({"()"});
    }
    else if (n <= 0) {
        return vector<string>();
    }

    set<string> ans;
    for (int j=1; j<=n-j; ++j) {
        vector<string> pre1 = generateParenthesis(n-j);
        vector<string> pre2 = generateParenthesis(j);

        for (size_t i=0; i<pre1.size(); ++i) {
            for (size_t j=0; j<pre2.size(); ++j) {
                ans.insert(pre1[i] + pre2[j]);
                ans.insert(pre2[j] + pre1[i]);
            }
            if (j==1) {
                ans.insert('(' + pre1[i] + ')');
            }
        }
    }

    return vector<string>(ans.begin(), ans.end());
}

int main(int argc, char* argv[])
{
    vector<string> ans = generateParenthesis(4);

    cout << ans.size() << endl;

    for (const auto& s : ans) {
        cout << s << endl;
    }
    return 0;
}
