
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// optimization this
bool isAnagrams(const vector<string>& vec, string str) {
    if (vec.empty()) {
        return false;
    }

    const string& base = vec[0];
    if (base.size() != str.size()) {
        return false;
    }

    int letter[26];
    memset(letter, 0, sizeof(letter));
    for (char ch : base) {
        int pos = ch - 'a';
        ++letter[pos];
    }

    for (char ch : str) {
        int pos = ch - 'a';
        if (letter[pos] < 1) {
            return false;
        }
        --letter[pos];
    }

    for (int i=0; i<26; ++i) {
        if (letter[i] != 0) {
            return false;
        }
    }

    return true;
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
