
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

// 使用dp

vector<string> generateParenthesis(int n) {
    vector<vector<string>> dp;
    dp.reserve(n+1);

    dp.push_back(vector<string>());
    dp.push_back(vector<string>({"()"}));

    for (int i=2; i<n+1; ++i) {
        set<string> s;
        for (int j=1; j<=i-j; ++j) {
            for (size_t m=0; m<dp[j].size(); ++m) {
                for (size_t n=0; n<dp[i-j].size(); ++n) {
                    s.insert(dp[j][m] + dp[i-j][n]);
                    s.insert(dp[i-j][n] + dp[j][m]);

                    if (j == 1) {
                        s.insert('(' + dp[i-j][n] + ')');
                    }
                }
            }
        }
        dp.push_back(vector<string>(s.begin(), s.end()));
    }
    return dp[n];
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
