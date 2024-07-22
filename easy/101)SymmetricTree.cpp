class Solution {
public:
    bool isEqual(TreeNode* left,TreeNode* right){
        if(!left && !right){
            return true;
        }
        else if(!left || !right){
            return false;
        }

        else if(left->val != right->val){
            return false;
        }

        return isEqual(left->left,right->right) && isEqual(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return false;
        }
        return isEqual(root->left,root->right);
    }
};