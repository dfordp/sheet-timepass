class Solution {
    int depth=0;
public:
    void helper(TreeNode* root,int curr=0){
        if(!root){
            return;
        }
        helper(root->left,curr+1);
        helper(root->right,curr+1);
        depth = max(depth,curr);
    }

    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        helper(root);
        return depth+1;
    }
};