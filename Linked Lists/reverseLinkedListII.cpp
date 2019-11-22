// Reverse Linked List II
#include <iostream>
#include <tuple>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

std::pair<ListNode*, ListNode*> reverseList(ListNode* head) {
    ListNode dummy(0);
    ListNode* pre = &dummy;
    pre -> next = head;
    auto curr = pre, tmp = pre;
    while (curr && pre -> next) {
        tmp = pre -> next;
        pre -> next = pre -> next -> next;
        tmp -> next = curr;
        curr = tmp;
    }
    head -> next = nullptr;

    return std::make_pair(curr, head);
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummy(0);
    ListNode* pre = &dummy;
    pre -> next = head;

    auto it = pre;
    while (--m) {it = it -> next; --n;}
    auto n_head = it; while (n--) it = it -> next;
    auto n_tail = it -> next; it -> next = nullptr;
    auto res = reverseList(n_head -> next);
    n_head -> next = res.first;
    res.second -> next = n_tail;
    return pre -> next;
}


int main() {
    auto l1 = ListNode(3);
    auto l2 = ListNode(5);
    auto l3 = ListNode(3);
    auto l4 = ListNode(4);
    auto l5 = ListNode(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l2.next = nullptr;
    auto res = reverseBetween(&l1, 1, 2);
    while (res) {
        std::cout << res -> val << " ";
        res = res -> next;
    }
    return 0;
}