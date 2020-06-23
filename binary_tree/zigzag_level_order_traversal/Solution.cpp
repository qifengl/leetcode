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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root != nullptr) {
            TreeNode* node = root;
            deque<TreeNode*> layer_front_end;
            deque<TreeNode*> layer_end_front;
            layer_front_end.push_back(node);
            bool front_end_tag = true;
            while((front_end_tag && !(layer_front_end.empty())) || (!front_end_tag && !(layer_end_front.empty()))) {
                vector<int> this_layer_result;
                if (front_end_tag) {
                    int layer_size = layer_front_end.size();
                    for (int i = 0; i < layer_size; i++) {
                        TreeNode* this_node = layer_front_end.front();
                        this_layer_result.push_back(this_node->val);
                        if (this_node->left) {
                            layer_end_front.push_back(this_node->left);
                        }
                        if (this_node->right) {
                            layer_end_front.push_back(this_node->right);
                        }
                        layer_front_end.pop_front();
                    }
                } else {
                    int layer_size = layer_end_front.size();
                    for (int i = 0; i < layer_size; i++) {
                        TreeNode* this_node = layer_end_front.back();
                        this_layer_result.push_back(this_node->val);
                        if (this_node->right) {
                            layer_front_end.push_front(this_node->right);
                        }
                        if (this_node->left) {
                            layer_front_end.push_front(this_node->left);
                        }
                        layer_end_front.pop_back();
                    }
                }
                front_end_tag = !(front_end_tag);
                result.push_back(this_layer_result);
            }
        }
        return result;
    }
};
