class Solution {
    int res;
public:
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }

        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);
        leftMax = max(leftMax,0);
        rightMax= max(rightMax,0);

        res = max(res,root->val + leftMax + rightMax);

        return root->val + max(leftMax,rightMax);
    }
    int maxPathSum(TreeNode* root) {
        res = root->val;

        dfs(root);
        return res;
    }
};