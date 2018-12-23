
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool isAnagrams(const vector<string>& vec, string str) {
    if (vec.empty()) {
        return false;
    }

    string base = vec[0];
    if (base.size() != str.size()) {
        return false;
    }

    sort(base.begin(), base.end());
    sort(str.begin(), str.end());

    if (base == str) {
        return true;
    }

    return false;
}

// brute force, compare each one
// time limit exceed
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;

    for (const string& str : strs) {
        bool inserted = false;
        for (auto& vec : ans) {
            if (isAnagrams(vec, str)) {
                vec.push_back(str);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            vector<string> vec{str};
            ans.push_back(vec);
        }
    }

    return ans;
}

int main(int argc, char* argv[]) {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    auto ans = groupAnagrams(strs);

    for (const auto& vec : ans) {
        for (const string& str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
