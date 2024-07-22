class Solution {
    int diff = INT_MAX;
    TreeNode *prev = NULL;
public:
    void dfs(TreeNode* root){

        if(!root){
            return;
        }
        
        dfs(root->left);
        if(prev){
            diff = min(diff , abs(prev->val - root->val));
        }
        prev = root;
        dfs(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return diff;
    }
};