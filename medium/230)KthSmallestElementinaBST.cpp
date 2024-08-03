class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
            curr = s.top();
            s.pop();
            if(--k==0){
                return curr->val;
            }
            curr=curr->right;
        }
        return -1; 
    }
};