class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int i=0,j=1;
        
       while(j<arr.size()){
            int d=arr[j]-arr[i];
            if(i!=j && d==x)return 1;
            else if(d>x)i++;
            else j++;
        }
        
        return -1;
    }
};