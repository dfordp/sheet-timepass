class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	     int n = nums.size();
        vector<pair<int, int>> arrPos(n);
        for (int i = 0; i < n; ++i) {
            arrPos[i] = {nums[i], i};
        }
        
        sort(arrPos.begin(), arrPos.end());

        vector<bool> visited(n, false);
         
        int swaps = 0;
        
         for (int i = 0; i < n; ++i){
            if (visited[i] || arrPos[i].second == i) {
                continue;
            }
            
            int cycleSize = 0;
            int x = i;
            
            while (!visited[x]) {
                visited[x] = true;
                x = arrPos[x].second;
                cycleSize++;
            }
            
            if (cycleSize > 0) {
                swaps += (cycleSize - 1);
            }
            
         }
             return swaps;
	}
};