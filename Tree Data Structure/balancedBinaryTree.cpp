#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int height(TreeNode* node, bool& balanced_) {

    if (!node) {
        return 0;
    }

    auto height1 = height(node -> left, balanced_);
    auto height2 = height(node -> right, balanced_);

    if (abs(height1 - height2) > 1) {
        balanced_ = false;
    }

    return std::max(height1, height2) + 1;
}

int isBalanced(TreeNode* root) {
    bool result = true;
    height(root, result);
    return result;
}