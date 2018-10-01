
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
        return vector<string>({""});
    }

    vector<string> ans;
    for (int j=0; n-j-1>=0; ++j) {
        vector<string> pre1 = generateParenthesis(n-j-1);
        vector<string> pre2 = generateParenthesis(j);

        for (size_t i=0; i<pre1.size(); ++i) {
            for (size_t j=0; j<pre2.size(); ++j) {
                ans.push_back('(' + pre1[i] + ')' + pre2[j]);
            }
        }
    }
    return ans;
}

int main(int argc, char* argv[])
{
    vector<string> ans = generateParenthesis(5);

    cout << ans.size() << endl;

    for (const auto& s : ans) {
        cout << s << endl;
    }
    return 0;
}
