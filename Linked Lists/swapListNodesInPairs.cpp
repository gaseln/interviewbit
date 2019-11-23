// Swap List Nodes in Pairs
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0);
    ListNode* pre = &dummy;
    pre -> next = head;
    ListNode* curr = pre;
    ListNode* tmp = pre;
    ListNode* res = head;
    bool flag = true;
    while (pre -> next && pre -> next -> next && pre -> next -> next -> next) {
        curr = pre -> next;
        tmp = pre -> next -> next;
        if (flag) {res = tmp; flag = false;}
        pre -> next = pre -> next -> next -> next;
        tmp -> next = curr;
        curr -> next = (pre -> next -> next) ? pre -> next -> next : pre -> next;
    }

    if (pre -> next && pre -> next -> next) {
        if (flag) {res = pre -> next -> next; }
        pre -> next -> next -> next = pre -> next;
        pre -> next -> next = nullptr;
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
    l4.next = nullptr;
    auto pre = &l1;
    auto res = swapPairs(pre);
    while (res) {
        std::cout << res -> val << " ";
        res = res -> next;
    }
    return 0;
}