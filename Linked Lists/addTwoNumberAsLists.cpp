// Add Two Numbers As Lists
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int curr_sum, a, b, memory = 0;
    ListNode dummy(0);
    ListNode* pre = &dummy;
    ListNode* res = l1;
    ListNode* tail = l2;
    pre -> next = l1;
    while (l1 || l2) {
        a = (l1) ? l1 -> val : 0;
        b = (l2) ? l2 -> val : 0;
        curr_sum = memory + a + b;
        memory = curr_sum / 10;
        curr_sum %= 10;
        pre -> next -> val = curr_sum;
        if (l1) l1 = l1 -> next;
        if (l2) l2 = l2 -> next;
        pre -> next -> next = (l1) ? l1 : l2;
        if (pre -> next -> next) pre -> next = pre -> next -> next;
    }
    pre -> next -> next = (memory) ? tail : nullptr;
    tail -> val = memory;
    tail -> next = nullptr;
    return res;
}

int main() {
    ListNode l1(5);
    ListNode l2(5);
    auto res = addTwoNumbers(&l1, &l2);
    while (res) {
        std::cout << res -> val << " ";
        res = res -> next;
    }
    return 0;
}