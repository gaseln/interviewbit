// K Reverse Linked List
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

std::pair<ListNode*, ListNode*> subListReverse(ListNode* head) {
    ListNode dummy(0);
    ListNode* pre = &dummy;
    pre -> next = head;
    auto curr = pre, tmp = pre;
    while (curr && pre -> next) {
        tmp = pre -> next;
        pre -> next = pre -> next -> next;
        tmp -> next = curr;
        curr = tmp;
    }
    head -> next = nullptr;

    return std::make_pair(curr, head);
}

ListNode* reverseList(ListNode* head, int k) {
    ListNode dummy(0);
    ListNode* pre = &dummy;
    ListNode fake_head_node(0);
    ListNode* fake_head = &fake_head_node;
    pre -> next = fake_head;
    fake_head -> next = head;
    auto tmp = fake_head, tmp2 = fake_head;
    int counter;
    while (pre -> next) {
        tmp = pre -> next;
        counter = 0;
        while (counter++ < k && pre -> next) {pre -> next = pre -> next -> next;}
        if (!pre -> next) {break;}
        tmp2 = pre -> next -> next;
        pre -> next -> next = nullptr;
        auto res = subListReverse(tmp -> next);
        tmp -> next = res.first;
        pre -> next = res.second;
        pre -> next -> next = tmp2;
    }

    return fake_head -> next;
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
    l5.next = nullptr;
    auto res = reverseList(&l1, 2);
    while (res) {
        std::cout << res -> val << " ";
        res = res -> next;
    }
    return 0;
}