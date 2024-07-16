class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int start = prices[0];
        for(int x:prices){
            if(start<x){
                maxProfit+=x-start;
            }
            start=x;
        }
        return maxProfit;
    }
};