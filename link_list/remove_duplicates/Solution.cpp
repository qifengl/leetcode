/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* ptr_1 = head;
        ListNode* ptr_2 = head->next;
        while (ptr_2) {
            if (ptr_2->val == ptr_1->val) {
                ptr_1->next = ptr_2->next;
                delete ptr_2;
            } else {
                ptr_1 = ptr_2;
            }
            ptr_2 = ptr_1->next;
        }
        return head;
    }
};
