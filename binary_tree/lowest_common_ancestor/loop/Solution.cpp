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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> father_map;
        getFatherMap(root, father_map);
        TreeNode* p_ancestor = p;
        while (p_ancestor != nullptr) {
            if (checkAncestor(p_ancestor, q, father_map)) {
                return p_ancestor;
            }
            p_ancestor = father_map[p_ancestor];
        }
        return root;
    }
    
    void getFatherMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& father_map) {
        TreeNode* node = root;
        queue<TreeNode*> layer_nodes;
        layer_nodes.push(root);
        father_map[root] = nullptr;
        while (!(layer_nodes.empty())) {
            int layer_size = layer_nodes.size();
            for (int i = 0; i < layer_size; i++) {
                TreeNode* this_node = layer_nodes.front();
                if (this_node->left) {
                    father_map[this_node->left] = this_node;
                    layer_nodes.push(this_node->left);
                }
                if (this_node->right) {
                    father_map[this_node->right] = this_node;
                    layer_nodes.push(this_node->right);
                }
                layer_nodes.pop();
            }
        }
    }

    //check whether first is ancestor of second
    bool checkAncestor(TreeNode* first, TreeNode* second, unordered_map<TreeNode*, TreeNode*>& father_map) {
        TreeNode* second_ = second;
        if (first == second_) {
            return true;
        } else {
            while (second_ != nullptr){
                second_ = father_map[second_];
                if (second_ == first) {
                    return true;
                }
            }
        }
        return false;
    }
};
