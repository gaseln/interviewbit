// Rotate List
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    auto tail = head;

    if (!head) return head;

    int length = 1;
    while (tail -> next) {
        tail = tail -> next;
        length++;
    }

    k = k % length;
    if (!k) return head;

    int count = length - k;
    auto new_tail = head;

    while (--count) {
        new_tail = new_tail -> next;
    }

    auto new_head = new_tail -> next;
    new_tail -> next = nullptr;
    tail -> next = head;
    return new_head;
}