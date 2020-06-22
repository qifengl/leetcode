/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getDepthStatus(root)[0];
    }
    // return value: {status, depth}
    vector<int> getDepthStatus(TreeNode* node) {
        if (node == nullptr) {
            return {1, 0};
        } else {
            vector<int> left_tree_status = getDepthStatus(node->left);
            vector<int> right_tree_status = getDepthStatus(node->right);
            if (left_tree_status[0] == 1 && right_tree_status[0] == 1 && abs(left_tree_status[1]-right_tree_status[1]) <= 1) {
                return {1, max(left_tree_status[1], right_tree_status[1])+1};
            } else {
                return {0, 0};
            }
        }

    }
};
