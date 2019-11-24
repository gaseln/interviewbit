// List Cycle
// consulted discussion at https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C%2B%2B-with-Detailed-Alogrithm-Description
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode dummy(0);
    ListNode* pre = &dummy;
    pre -> next = head;
    ListNode* slow = pre;
    ListNode* fast = pre;
    while (fast -> next && fast -> next -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
        if (slow == fast) {
            ListNode* slow_2 = pre;
            while (slow_2 != slow) {
                slow = slow -> next;
                slow_2 = slow_2 -> next;
            }
            return slow;
        }
    }
    return nullptr;

}

int main() {
    auto l1 = ListNode(3);
    auto l2 = ListNode(2);
    auto l3 = ListNode(0);
    auto l4 = ListNode(-4);
    auto l5 = ListNode(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l2;
    l5.next = &l2;
    auto res = detectCycle(&l1);
    if (res == &l2) {
        std::cout << "correct";
    } else {
        std::cout << "error";
    }
    return 0;
}