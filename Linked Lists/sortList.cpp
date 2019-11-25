// Sort List
#include <iostream>


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* sortList(ListNode* head) {

    if (!head || !head -> next) {
        return head;
    }

    int count = 1;
    auto tmp = head;
    while (tmp -> next) {tmp = tmp -> next; count++;}
    tmp = head;
    count /= 2;
    while (--count) {tmp = tmp -> next;}
    auto n_head = tmp -> next;
    tmp -> next = nullptr;
    head = sortList(head);
    n_head = sortList(n_head);
    ListNode dummy(0);
    ListNode* pre = &dummy;
    ListNode* tmp_n = pre;
    while (head && n_head) {
        if (head -> val <= n_head -> val) {
            tmp_n -> next = head;
            tmp_n = head;
            head = head -> next;
        } else {
            tmp_n -> next = n_head;
            tmp_n = n_head;
            n_head = n_head -> next;
        }
    }

    if (!head) {tmp_n -> next = n_head;} else {tmp_n -> next = head;}

    return pre -> next;
}

int main() {
    auto l1 = ListNode(4);
    auto l2 = ListNode(2);
    auto l3 = ListNode(1);
    auto l4 = ListNode(3);
    auto l5 = ListNode(2);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    auto pre = sortList(&l1);
    while (pre) {
        std::cout << pre -> val << " ";
        pre = pre -> next;
    }
    return 0;
}