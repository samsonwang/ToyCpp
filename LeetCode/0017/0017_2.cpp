

// leetcode 上的方法，使用了递归，oops
class Solution {
    char mMap[8][4] = {
        {'a', 'b', 'c', '#'},
        {'d', 'e', 'f', '#'},
        {'g', 'h', 'i', '#'},
        {'j', 'k', 'l', '#'},
        {'m', 'n', 'o', '#'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v', '#'},
        {'w', 'x', 'y', 'z'},
    };

public:
    vector<string> letterCombinations(string digits) {

        vector<string> result;

        backTrack(digits, result, "", 0);
        return result;
    }

    void backTrack(string &digits, vector<string> &result, string combination, int index) {
        if (index >= digits.length()) {
            if (combination.empty()) {
                return;
            }
            result.push_back(combination);
            return;
        }
        //combination += digits[index];
        for (char c : mMap[digits[index] - '2']) {
            if (c == '#')
                continue;

            combination += c;
            backTrack(digits, result, combination, index+1);

            // 这里为什么要删去最后一个呢？
            // 因为之前在尾部追加了一个c
            combination.erase(combination.end() - 1);
        }
    }
};
