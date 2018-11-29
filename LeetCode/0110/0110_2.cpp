

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// fastest from leetcode
class Solution {
public:
    int getDepth(TreeNode* node, int depth, bool& balanced) {
        if (!node || !balanced) return depth;

        int leftDepth = getDepth(node->left, depth+1, balanced);
        int rightDepth = getDepth(node->right, depth+1, balanced);

        if (!balanced) return depth;

        const int result = leftDepth - rightDepth;

        balanced = result == 0 || result == -1 || result == 1;

        return leftDepth > rightDepth ? leftDepth : rightDepth;
    }

    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        getDepth(root, 0, balanced);
        return balanced;
    }
};

// 将balanced作为参数传入，自底向上查
