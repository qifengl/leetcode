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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= max || root->val <= min) {
            return false;
        }
        bool left_valid = isValidBST(root->left, min, root->val);
        bool right_valid = isValidBST(root->right, root->val, max);
        return left_valid&&right_valid;
    }
};
