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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getDepth(TreeNode* root, int depthBase) {
    if (root == nullptr) {
        return depthBase;
    }

    int left = getDepth(root->left, depthBase);

    int right = getDepth(root->right, depthBase);

    int max = left > right ? left : right;

    return max + depthBase + 1;
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    // is balanced this layer
    int left = getDepth(root->left, 0);
    int right = getDepth(root->right, 0);

    int diff = left - right;
    if (diff > 1 || diff < -1) {
        return false;
    }

    // is balanced in sub layer
    return isBalanced(root->left) && isBalanced(root->right);
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

    setTree2(&root);

    bool ret = isBalanced(&root);
    if (ret) {
        printf("is balanced\n");
    }
    else {
        printf("is not balanced\n");
    }

    return 0;
}
