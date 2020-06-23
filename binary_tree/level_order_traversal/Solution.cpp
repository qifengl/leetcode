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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root) {
            queue<TreeNode*> this_layer;
            this_layer.push(root);
            while (!(this_layer.empty())) {
                vector<int> this_layer_values;
                int this_layer_size = this_layer.size();
                for (int i = 0; i < this_layer_size; i++) {
                    TreeNode* this_node = this_layer.front();
                    this_layer_values.push_back(this_node->val);
                    if (this_node->left) {
                        this_layer.push(this_node->left);
                    }
                    if (this_node->right) {
                        this_layer.push(this_node->right);
                    }
                    this_layer.pop();
                }
                result.push_back(this_layer_values);
            }
        }
        return result;
    }
};
