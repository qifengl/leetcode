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
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        TreeNode* node = root;
        if (node != nullptr) {
            TreeNode* left_son_node = node->left;
            TreeNode* right_son_node = node->right;
            int left_max_depth = maxDepth(left_son_node);
            int right_max_depth = maxDepth(right_son_node);
            max_depth = (left_max_depth > right_max_depth)?(left_max_depth+1):(right_max_depth+1);
        } else {
            max_depth = 0;
        }
        return max_depth;
    }
};
