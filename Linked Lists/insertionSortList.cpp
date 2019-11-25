// Insertion Sort List
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* insertionSortList(ListNode* head) {
    ListNode* begin = head;
    if (!begin) {return head;}
    ListNode* next = head -> next;
    begin -> next = nullptr;
    ListNode* tmp1 = head;
    while (next) {
        auto tmp = next;
        next = next -> next;
        tmp1 = begin;

        if (begin -> val >= tmp -> val) {
            tmp -> next = begin;
            begin = tmp;
            continue;
        }
        while (tmp1 -> next) {
            if (tmp1 -> next -> val >= tmp -> val) {
                tmp -> next = tmp1 -> next;
                tmp1 -> next = tmp;
                break;
            }
            tmp1 = tmp1 -> next;
        }

        if (!tmp1 -> next) {tmp1 -> next = tmp; tmp -> next = nullptr;}
    }

    return begin;
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
//    l4.next = &l5;
    auto pre = insertionSortList(&l1);
    while (pre) {
        std::cout << pre -> val << " ";
        pre = pre -> next;
    }
    return 0;
}