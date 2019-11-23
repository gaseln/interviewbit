// Reorder List
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode dummy(0);
    ListNode* pre = &dummy;
    pre -> next = head;
    ListNode* curr = pre;
    ListNode* tmp = pre;
    while (pre -> next) {
        tmp = pre -> next;
        pre -> next = pre -> next -> next;
        tmp -> next = curr;
        curr = tmp;
    }
    if (!head) return head;
    head -> next = nullptr;

    return curr;
}

ListNode* reorderList(ListNode* head) {
    auto res = head;
    if (!head) return head;
    ListNode dummy(0);
    ListNode* pre = &dummy;
    pre -> next = head;
    int count = 0;
    while (pre -> next) {pre -> next = pre -> next -> next; count++;}

    pre -> next = head;
    count = (count + 1) / 2;
    while (--count) pre -> next = pre -> next -> next;
    ListNode* head_2 = pre -> next -> next;
    pre -> next -> next = nullptr;
    head_2 = reverseList(head_2);
    auto tmp1 = head, tmp2 = head_2;
    while (head) {
        tmp1 = head -> next;
        if (head_2) tmp2 = head_2 -> next;
        head -> next = head_2;
        if (head_2) head_2 -> next = tmp1;
        head = tmp1;
        head_2 = tmp2;
    }

    return res;
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
    auto pre = &l1;
    reorderList(pre);
    while (pre) {
        std::cout << pre -> val << " ";
        pre = pre -> next;
    }
    return 0;
}