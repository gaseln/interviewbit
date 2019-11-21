// Remode Nth Node From End of List
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) return head;
    auto dummy = ListNode(0);
    dummy.next = head;

    int count = 2;
    auto l = head;
    while (l -> next) {
        l = l -> next;
        count++;
    }
    l = &dummy;
    count = count - n;

    if (count < 1) return head -> next;

    while (--count) l = l -> next;

    l -> next = l -> next -> next;
    return dummy.next;
}

int main() {
    auto l1 = ListNode(1);
    auto l2 = ListNode(1);
    auto l3 = ListNode(1);
    auto l4 = ListNode(1);
    auto l5 = ListNode(1);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    auto res = removeNthFromEnd(&l1, 2);
    return 0;
}