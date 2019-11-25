// Partition List
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode less_(0); ListNode* less = &less_;
    ListNode not_less_(0); ListNode* not_less = &not_less_;
    ListNode* it1 = less; ListNode* it2 = not_less;
    while (head) {
        if (head -> val < x) {
            it1 -> next = head;
            it1 = head;
        } else {
            it2 -> next = head;
            it2 = head;
        }

        head = head -> next;
    }

    it1 -> next = not_less -> next;
    it2 -> next = nullptr;

    return less -> next;
}

int main() {
    auto l1 = ListNode(1);
    auto l2 = ListNode(4);
    auto l3 = ListNode(3);
    auto l4 = ListNode(2);
    auto l5 = ListNode(2);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = nullptr;
    auto pre = partition(&l1, 3);
    while (pre) {
        std::cout << pre -> val << " ";
        pre = pre -> next;
    }
    return 0;
}