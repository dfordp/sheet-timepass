class Solution {
public:
    bool dfs(TreeNode* root , int targetSum ,int currSum ){
        if(!root){
            return false;
        }

        currSum += root->val;
        if(!root->left && !root->right){
            return currSum==targetSum;
        }

        return (dfs(root->left,targetSum,currSum) || dfs(root->right,targetSum,currSum) );
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum,0);
    }
};