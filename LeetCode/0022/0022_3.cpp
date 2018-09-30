
// leetcode fastest sample

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesis(n, 0, 0, "", result);
        return result;
    }

    void generateParenthesis(int n, int left, int right, string sub,
                             vector<string> &result) {
        if(right == n)
            result.push_back(sub);
        if(left != n)
            generateParenthesis(n, left+1, right, sub + "(", result);
        if(right < left)
            generateParenthesis(n, left, right+1, sub + ")", result);
    }
};
