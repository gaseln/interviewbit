// Copy List
#include <unordered_map>

class RandomListNode {
public:
    int label;
    RandomListNode* next;
    RandomListNode* random;

    RandomListNode() {}

    RandomListNode(int _label) {
        label = _label;
        next = nullptr;
        random = nullptr;
    }
};

RandomListNode* copyRandomList(RandomListNode* head) {
    if (!head) { return nullptr;}
    RandomListNode* n_head = new RandomListNode(head -> label);
    auto curr = head;
    auto n_curr = n_head;

    while (curr -> next) {
        curr = curr -> next;
        RandomListNode* n_list = new RandomListNode(curr -> label);
        n_curr -> next = n_list;
        n_curr = n_list;
    }

    curr = head;
    n_curr = n_head;
    std::unordered_map<RandomListNode *, RandomListNode *> old_to_new;

    while (curr) {
        old_to_new[curr] = n_curr;
        curr = curr -> next;
        n_curr = n_curr -> next;
    }

    curr = head;
    n_curr = n_head;

    while (curr) {
        n_curr -> random = old_to_new[curr -> random];
        curr = curr -> next;
        n_curr = n_curr -> next;
    }

    return n_head;
}

int main() {
    RandomListNode l1(2);
    RandomListNode l2(3);
    l1.next = &l2;
    l1.random = &l2;
    l2.random = &l2;
    auto res = copyRandomList(&l1);
}