class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int r=0;
        int c=0;
        int dr=0;
        int dc=1;

         while(ans.size()<m*n){
            ans.push_back(matrix[r][c]);
            matrix[r][c]=INT_MAX;

            if(r+dr>=n || r+dr <0 || c+dc>=m || c+dc<0 || matrix[r+dr][c+dc]==INT_MAX){
                swap(dr,dc);
                dc*=-1;
            }

            r+=dr;
            c+=dc;
        } 
        return ans;
    }
};