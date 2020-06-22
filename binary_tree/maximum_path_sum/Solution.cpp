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
private:
    vector<int> allAlternatives;
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        maxPathSum(root, result);
        return result;
    }

    int maxPathSum(TreeNode* root, int &val) {
        if (root == nullptr) {
            return 0;
        }
        TreeNode* node = root;
        int leftTreeValue = maxPathSum(node->left, val);
        int rightTreeValue = maxPathSum(node->right, val);
        int max_val_1 = node->val+max(0, leftTreeValue)+max(0, rightTreeValue);
        int max_val_2 = node->val+max(max(leftTreeValue, rightTreeValue), 0);
        val = max(max(max_val_1, max_val_2), val);
        return max_val_2;
    }
};
