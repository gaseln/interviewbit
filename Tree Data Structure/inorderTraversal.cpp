#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* root, std::vector<int>& result) {
    if (root== nullptr) {
        return;
    }
    dfs(root->left, result);
    result.push_back(root->val);
    dfs(root->right, result);
}

std::vector<int> inorderTraversal(TreeNode* A) {
    std::vector<int> result;
    dfs(A, result);
    return result;
}