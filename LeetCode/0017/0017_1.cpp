
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

static const auto fast = [](){
                             ios_base::sync_with_stdio(false);
                             cin.tie(NULL);
                             return 0;
                         }();

// 这道题看起来不难，需要解决的是
vector<string> letterCombinations(string digits) {

    vector<string> ans;

    if (digits.empty()) {
        return ans;
    }

    vector<int> nums;
    for (char ch : digits) {
        int n = ch - '0';
        nums.push_back(n);
    }

    vector<string> letters {"",  "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // 类似于数学进位的思想
    vector<int> carry(nums.size(), 0);

    do{
        // 根据carry形成一个字符串
        string str;
        for (size_t i=0; i<carry.size(); ++i) {
            str += letters[nums[i]] [carry[i]];
        }
        ans.push_back(str);

        // 对 carry 增加 1
        int c = 1;
        for (int i=carry.size()-1; i >= 0; --i) {
            int d = carry[i] + c;
            if (d >= letters[nums[i]].size()) {
                carry[i] = 0;
                c = 1;
            }
            else {
                carry[i] = d;
                c = 0;
                break;
            }
        }

        if ( 1 == c) {
            break;
        }

    } while (1);

    return ans;
}

int main(int argc, char* argv[]) {
    vector<string> ans1 = letterCombinations("234");

    for (const auto& s : ans1) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
