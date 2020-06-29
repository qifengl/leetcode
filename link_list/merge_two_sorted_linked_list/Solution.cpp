/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* result_ = result;
        ListNode* l1_ = l1;
        ListNode* l2_ = l2;
        while (l1_ || l2_) {
            if (l1_ && l2_) {
                if (l1_->val < l2_->val) {
                    result_->next = l1_;
                    l1_ = l1_->next;
                } else {
                    result_->next = l2_;
                    l2_ = l2_->next;
                }
            } else if (l1_) {
                result_->next = l1_;
                l1_ = l1_->next;
            } else if (l2_) {
                result_->next = l2_;
                l2_ = l2_->next;
            }
            result_ = result_->next;
        }
        return result->next;
    }
};
