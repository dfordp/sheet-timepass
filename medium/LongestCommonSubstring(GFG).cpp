class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        int dp[n+1][m+1];
        int l=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0|| j==0)
                dp[i][j]=0;
                else if (s1[i-1]==s2[j-1])
                {
                dp[i][j]=dp[i-1][j-1]+1;
                l=max(l,dp[i][j]);
                }
                else
                dp[i][j]=0;
            }
        }
        return  l;
    }
};