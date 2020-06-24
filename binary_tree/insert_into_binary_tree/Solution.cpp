/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (root->val == val) {
            return root;
        }
        if (val < root->val ) {
            if(root->left){
                root->left = insertIntoBST(root->left, val); 
            } else {
                root->left = new TreeNode(val);
            }
        } 
        if (val > root->val) {
            if (root->right) {
                root->right = insertIntoBST(root->right, val);
            } else {
                root->right = new TreeNode(val);
            }
        }
        return root;
    }
};
