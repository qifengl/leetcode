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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root) {
            queue<TreeNode*> this_layer_nodes;
            this_layer_nodes.push(root);
            while (!(this_layer_nodes.empty())) {
                vector<int> this_layer_result;
                int this_layer_size = this_layer_nodes.size();
                for (int i = 0; i < this_layer_size; i++) {
                    TreeNode* this_node = this_layer_nodes.front();
                    this_layer_result.push_back(this_node->val);
                    if (this_node->left) {
                        this_layer_nodes.push(this_node->left);
                    }
                    if (this_node->right) {
                        this_layer_nodes.push(this_node->right);
                    }
                    this_layer_nodes.pop();
                }
                result.push_back(this_layer_result);
            }
            reverse(result.begin(), result.end());
            return result;
        }
        return result;
    }
};
