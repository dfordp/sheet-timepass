class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root){
            return ans;
        }

        queue<TreeNode*> q;

        q.push(root);
        int i=0;

        while(q.size()){
            vector<int> temp;
            int s = q.size();

            while(s--){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(i++%2){
                reverse(temp.begin() , temp.end());
            }

            ans.push_back(temp);
        }

        return ans;
    }
};