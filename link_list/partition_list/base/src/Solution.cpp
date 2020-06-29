#include <queue>
#include <Solution.h>

using namespace std;

ListNode* Solution::partition(ListNode* head, int x) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* ptr1 = dummy;
    ListNode* ptr2 = dummy->next;
    queue<ListNode*> larger_nodes;
    while (ptr2) {
        if (ptr2->val < x) {
            ptr1->next = ptr2;
            ptr1 = ptr1->next;
            ptr2 = ptr1->next;
        } else {
            larger_nodes.push(ptr2);
            ptr2 = ptr2->next;
        }
    }
    while (!(larger_nodes.empty())) {
        ptr1->next = larger_nodes.front();
        ptr1 = ptr1->next;
        larger_nodes.pop();
    }
    ptr1->next = nullptr;
    return dummy->next;
}