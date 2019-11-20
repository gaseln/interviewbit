// Remove Duplicates From Sorted List
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    ListNode* res = head;
    ListNode* previous_head = head;
    while (head -> next != nullptr) {
        head = head -> next;
        if (head -> val != previous_head -> val) {
            previous_head -> next = head;
            previous_head = head;
        }
    }
    previous_head -> next = nullptr;
    return res;
}

