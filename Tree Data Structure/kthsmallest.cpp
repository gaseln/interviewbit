#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

void natorder(TreeNode* root, vector<int> &out) {
    if (root->left != nullptr) {
        natorder(root->left, out);
    }
    out.push_back(root->val);
    if (root->right != nullptr) {
        natorder(root->right, out);
    }
}
int kthsmallest(TreeNode* root, int k) {
    vector<int> out;
    natorder(root, out);
    return out[k-1];
}
