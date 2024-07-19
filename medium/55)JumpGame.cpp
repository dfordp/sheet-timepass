class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[nums.size()-1] = 1;

        for(int inx = nums.size()-2; inx>=0; inx--){
            bool val = false;
            for(int i=1; i<=nums[inx]; i++){
               if(inx + i < nums.size()) val = val || dp[inx + i];
            }
            dp[inx] = val;
        }
        return dp[0];
    }
};