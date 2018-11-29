/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstdio>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// my approach of bottoms up
int getDepth(TreeNode* root, int depthBase, bool& balanced) {
    if (root == nullptr) {
        return depthBase;
    }

    int left = getDepth(root->left, depthBase + 1, balanced);
    int right = getDepth(root->right, depthBase + 1, balanced);

    int max = left > right ? left : right;

    int diff = abs(left - right);
    if (diff > 1) {
        balanced = false;
        return max;
    }

    return max;
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    bool balanced = true;
    getDepth(root, 0, balanced);
    return balanced;
}

void setTree1(TreeNode* root) {

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);

    root->left->left->left = new TreeNode(4);
}

void setTree2(TreeNode* root) {

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(3);

    //    root->left->left->left = new TreeNode(4);

}

int main(int argc, char* argv[]) {

    TreeNode root(1);

    setTree1(&root);

    bool ret = isBalanced(&root);
    if (ret) {
        printf("is balanced\n");
    }
    else {
        printf("is not balanced\n");
    }

    return 0;
}
