// Remove Duplicates From Sorted List II
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* nextList(ListNode* head) {
    bool flag = false;
    ListNode* res = head;
    while (head -> next != nullptr) {
        head = head -> next;
        if (head -> val != res -> val) {
            flag = false;
            if (head == res -> next) {
                break;
            }
            res = head;
        } else {
            flag = true;
        }
    }

    return (flag) ? nullptr : res;

}
ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head -> next == nullptr) {
        return head;
    }

    // finding new head (res)
    auto res = nextList(head);

    if (res == nullptr) {
        return res;
    }

    ListNode* previousList = res;
    ListNode* nList = previousList -> next;

    while (nList!= nullptr) {
        nList = nextList(nList);
        previousList -> next = nList;
        previousList = nList;
        if (nList != nullptr) {
            nList = nList -> next;
        }
    }

    return res;
}