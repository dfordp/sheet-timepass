class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int l=0,b=height.size()-1;

        while(l<b){
            int currentArea =  min(height[l],height[b])*(b-l) ;
            maxArea = max(currentArea,maxArea);

            if(height[l]<height[b]){
                l++;
            }
            else{
                b--;
            }
        }
        return maxArea;
    }
};