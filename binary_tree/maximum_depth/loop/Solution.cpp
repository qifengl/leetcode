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
        queue<TreeNode*> node_list;
        if (root == nullptr) {
            return 0;
        } else {
            node_list.push(root);
        }
        int max_depth = 0;
        while (!(node_list.empty())) {
            max_depth++;
            int this_layer_size = node_list.size();
            for (int i = 0; i < this_layer_size; i++) {
                TreeNode* this_node = node_list.front();
                if (this_node->left) {
                    node_list.push(this_node->left);
                }
                if (this_node->right) {
                    node_list.push(this_node->right);
                }
                node_list.pop();
            }
        }
        return max_depth;
    }
};
