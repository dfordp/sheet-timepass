class Solution {
    void helper(vector<vector<char>>& grid,int i,int j){
        int m=grid.size(),n=grid[0].size();
        if(i<0||i==m||j<0||j==n || grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        helper(grid,i-1,j);
        helper(grid,i+1,j);
        helper(grid,i,j-1);
        helper(grid,i,j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n=m ? grid[0].size() : 0, islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    helper(grid,i,j);
                }
            }
        }
        return islands;
    }
};