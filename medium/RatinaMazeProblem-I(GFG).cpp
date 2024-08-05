class Solution {
    
      bool isSafe(int x,int y, int n, vector<vector<int>> &visited,
                vector<vector<int>> &mat)
    {
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && mat[x][y]==1){
            return true;
        }else{
            return false;
        }
    }
    
    void solve(vector<vector<int>> &mat, int n, int x, int y,
            vector<vector<int>> visited, string path, vector<string> &ans)
    {
        //base case
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        
        //4 choices
        //down
        int newx=x+1;
        int newy=y;
        if(isSafe(newx,newy,n,visited,mat)){
            path.push_back('D');
            solve(mat,n,newx,newy,visited,path,ans);
            path.pop_back();
        }
        //up
        newx=x-1;
        newy=y;
        if(isSafe(newx,newy,n,visited,mat)){
            path.push_back('U');
            solve(mat,n,newx,newy,visited,path,ans);
            path.pop_back();
        }
        //left
        newx=x;
        newy=y-1;
        if(isSafe(newx,newy,n,visited,mat)){
            path.push_back('L');
            solve(mat,n,newx,newy,visited,path,ans);
            path.pop_back();
        }
        //right
        newx=x;
        newy=y+1;
        if(isSafe(newx,newy,n,visited,mat)){
            path.push_back('R');
            solve(mat,n,newx,newy,visited,path,ans);
            path.pop_back();
        }
        
        
        visited[x][y]=0;
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        
        if(mat[0][0]==0)
            return ans;
            
        string path = "";
        int i=0,j=0;
        vector<vector<int>> visited = mat;
        int n=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = 0;
            }
        }
        
        solve(mat,n,i,j,visited,path,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
