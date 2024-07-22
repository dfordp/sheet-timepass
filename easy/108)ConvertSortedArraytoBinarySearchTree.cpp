class Solution {
public:
    TreeNode* createBST(vector<int>&nums,int left,int right){
      TreeNode* newroot;
        if(left <= right)
        {
            int mid = (left+right) / 2;
            newroot = new TreeNode(nums[mid]);
            newroot->left = createBST(nums,left,mid-1);
            newroot->right = createBST(nums,mid+1,right);
            return newroot;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        return createBST(nums,left,right);
    }
};