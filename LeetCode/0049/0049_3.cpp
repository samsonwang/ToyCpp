
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// leetcode approach
// using unordered_map and multiset
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = strSort(s);
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto m : mp) {

            anagrams.push_back(m.second);
        }
        return anagrams;
    }
private:
    string strSort(string& s) {
        int count[26] = {0}, n = s.length();
        for (int i = 0; i < n; i++)
            count[s[i] - 'a']++;
        int p = 0;
        string t(n, 'a');
        for (int j = 0; j < 26; j++)
            for (int i = 0; i < count[j]; i++)
                t[p++] += j;
        return t;
    }
};

int main(int argc, char* argv[]) {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sln;
    auto ans = sln.groupAnagrams(strs);

    for (const auto& vec : ans) {
        for (const string& str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
