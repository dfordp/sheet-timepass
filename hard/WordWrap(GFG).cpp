class Solution {
public:
      int solve(int index , vector<int>&nums , int  k ,vector<int>& dp)
   {
       if(index >= nums.size()-1) return 0;


       if(dp[index]!=-1) return dp[index];
       int val = 0 ;
       int mini = 1e9;
       for(int i = index ; i < nums.size() ; i++)
       {
          val = val + nums[i];
          int gap = i - index;
          if(val + gap <= k && i < nums.size() - 1){
              int cost = pow(k - (val+gap) , 2) + solve(i+1 , nums , k , dp);
              mini = min(mini , cost);
          }
          else if(val + gap <= k && i == nums.size() - 1) return dp[index] = 0;
       }
       return dp[index] = mini;
   }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        vector<int>dp(n , -1);
        return solve(0 , nums , k , dp);
    } 
};

