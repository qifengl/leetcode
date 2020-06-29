#include <Solution.h>
#include <cstdio>

int main(int argc, char** argv) {
    ListNode* root = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(2);
    root->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    Solution s;
    ListNode* head = s.partition(root, 3);
    while (head) {
        printf("node_value: %d\n", head->val);
        head = head->next;
    }
}

