// Merge Two Sorted Lists
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    auto res = (l1 -> val <= l2 -> val) ? l1 : l2;
    auto prev = res;

    if (l1 -> val <= l2 -> val)
        l1 = l1 -> next;
    else l2 = l2 -> next;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1 -> val <= l2 -> val) {
            prev -> next = l1;
            prev = l1;
            l1 = l1 -> next;
        } else {
            prev -> next = l2;
            prev = l2;
            l2 = l2 -> next;
        }
    }

    if (l1 == nullptr) prev -> next = l2;
    else prev -> next = l1;

    return res;
}