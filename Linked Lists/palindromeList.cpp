// Palindrome List
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int lPalin(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return 1;
    }

    auto tmp = head;
    int count = 1;

    while (tmp -> next != nullptr) {
        tmp = tmp -> next;
        count++;
    }

    int middle = (count % 2 == 0) ? count / 2 - 1 : count / 2;
    auto first_half = head;
    while (middle > 0) {
        first_half = first_half->next;
        middle--;
    }

    ListNode* second_half;

    if (count % 2 == 0) {
        second_half = first_half->next;
    } else {
        second_half = new ListNode(first_half -> val);
        second_half -> next = first_half -> next;
    }

    tmp = head -> next;
    ListNode* tmp1 = head;
    ListNode* tmp2;

    while (tmp != first_half && count > 3) {
        tmp2 = tmp;
        tmp = tmp -> next;
        tmp2 -> next = tmp1;
        tmp1 = tmp2;
    }

    first_half->next = tmp1;
    head->next = nullptr;

    while (first_half -> val == second_half -> val) {
        first_half = first_half->next;
        second_half = second_half->next;
        if (first_half == nullptr) {
            return 1;
        }
    }

    return 0;
}

int main() {
    auto l1 = ListNode(1);
    auto l2 = ListNode(0);
    auto l3 = ListNode(0);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = nullptr;
    std::cout << lPalin(&l1);
    return 0;
}