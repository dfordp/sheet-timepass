class Solution {
public:
   int helper(TreeNode* root, long targetSum)
    {
        if (root == nullptr)
            return 0;

        int found = 0;
        if (root->val == targetSum)
            found = 1;

        int left_1 = helper(root->left, targetSum - root->val);
        int right_1 = helper(root->right, targetSum - root->val);

        return found + left_1 + right_1;
    }

    int pathSumEx(TreeNode* root, long targetSum) {
        if (root == nullptr)
            return 0;

        return helper(root, targetSum) + pathSumEx(root->left, targetSum) + pathSumEx(root->right, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        return pathSumEx(root,targetSum);
    }
};