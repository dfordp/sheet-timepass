class Solution {
    int ans=0;
public:
    void helper(TreeNode* root){
        if(root){
            if(root->left && !root->left->left && !root->left->right){
                ans+=root->left->val;
            }
            helper(root->left);
            helper(root->right);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        helper(root);
        return ans;
    }
};