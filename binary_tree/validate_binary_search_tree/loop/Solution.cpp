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
    vector<int> values;
public:
    bool isValidBST(TreeNode* root) {
        getValues(root);
        if(values.size() == 1 || values.size() == 0){
            return true;
        }
        for(auto iter = values.begin()+1; iter != values.end(); iter++){
            if(*(iter) <= *(iter - 1)){
                return false;
            }
        }
        return true;
    }

    void getValues(TreeNode* root){
        TreeNode* node = root;
        if(node){
            getValues(node->left);
            values.push_back(node->val);
            getValues(node->right);
        }
    }
};
