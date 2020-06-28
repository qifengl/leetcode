#include <Solution.h>

ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    if (m==n) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* seg_prev = dummy;
    ListNode* seg_begin;
    for (int i = 1; i < m; i++) {
        seg_prev = seg_prev->next;
    }
    seg_begin = seg_prev->next;
    ListNode* ptr1 = seg_begin;
    ListNode* ptr2 = seg_begin->next;
    for (int i = m; i < n; i++){
        ListNode* tmp = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = tmp;
    }
    seg_prev->next = ptr1;
    seg_begin->next = ptr2;
    return dummy->next;
}
