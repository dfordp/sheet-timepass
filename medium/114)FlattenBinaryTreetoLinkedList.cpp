class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }

        TreeNode* right_node = root->right;

        flatten(root->left);

        root->right = root->left;
        root->left = NULL;

        while(root->right)
            root=root->right;

        flatten(right_node);

        root->right = right_node;

    }
};