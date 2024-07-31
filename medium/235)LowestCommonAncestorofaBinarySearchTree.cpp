class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int temp = root->val; 

        if(p->val < temp && q->val < temp)
			 return lowestCommonAncestor(root->left, p, q);
        
        else if(p->val > temp && q->val > temp)
			return lowestCommonAncestor(root->right, p, q);

        else 
              return root;
    }
};