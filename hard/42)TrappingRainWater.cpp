class Solution {
public:
    int trap(vector<int>& height) {
         int ans=0;
        int l=0;
        int r=height.size()-1;
        int lmax=INT_MIN;
        int rmax=INT_MIN;

        while(l<r){
            if(height[l]<=height[r]){
                lmax=max(height[l],lmax);
                ans+=(lmax-height[l]);
                l++;
            }
            else{
                rmax=max(rmax,height[r]);
                ans+=(rmax-height[r]);
                r--;
            }
        }
        return ans;
    }
};