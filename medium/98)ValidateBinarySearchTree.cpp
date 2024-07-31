class Solution {
public:
    bool solve(TreeNode* root, long long max, long long min) {
        if (!root) {
            return true;
        }

        if (root->val <= min || root->val >= max) {
            return false;
        }

        return solve(root->left, root->val, min) && solve(root->right, max, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MAX, LONG_MIN);
    }
};