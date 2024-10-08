class Solution {
    bool ans;
public:
    int checkBalance(TreeNode* root){
        if(!root)
            return 0;
        if(!ans)
            return 0;
        int leftSubTree = checkBalance(root->left);
        int rightSubTree = checkBalance(root->right);
        if(abs(leftSubTree-rightSubTree) > 1){
            ans = false;
        }
        return 1 + max(leftSubTree, rightSubTree);
    }
    bool isBalanced(TreeNode* root) {
        ans = true;
        int temp = checkBalance(root);
        return ans;
    }
};