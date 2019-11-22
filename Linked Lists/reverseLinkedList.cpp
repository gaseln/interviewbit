// Reverse Linked List
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* reverseList(ListNode* A) {
    if (!A || !A -> next) return A;

    auto res = A -> next, tmp1 = A, tmp2 = A -> next;
    while (res) {
        res = res -> next;
        tmp2 -> next = tmp1;
        tmp1 = tmp2;
        tmp2 = res;
    }

    A -> next = nullptr;
    return tmp1;
}

int main() {
    auto l1 = ListNode(1);
    auto l2 = ListNode(2);
    auto l3 = ListNode(3);
    auto l4 = ListNode(4);
    auto l5 = ListNode(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    auto res = reverseList(&l1);
    while (res) {
        std::cout << res -> val << " ";
        res = res -> next;
    }
    return 0;
}