#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int isSameTree(TreeNode* p, TreeNode* q) {
    std::vector<TreeNode*> p_queue{p}, q_queue{q};

    for (int ind = 0; ind < p_queue.size(); ++ind) {

        if (!p_queue[ind] && !q_queue[ind]) {
            continue;
        }

        if (!p_queue[ind] || !q_queue[ind]) {
            return 0;
        }

        if (p_queue[ind]->val != q_queue[ind]->val) {
            return 0;
        }

        p_queue.push_back(p_queue[ind] -> left); p_queue.push_back(p_queue[ind] -> right);
        q_queue.push_back(q_queue[ind] -> left); q_queue.push_back(q_queue[ind] -> right);
    }

    return 1;
}