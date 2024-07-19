class Solution {
public:
    int countNeighbours(vector<vector<int>>& board, int i, int j, int m, int n) { //counting number of ones across all
        int count = 0; 
        
        for (int I = max(i-1, 0); I < min(i + 2, m); ++I)  //for edge elements
            for (int J = max(j - 1, 0); J < min(j + 2, n); ++J) {
                if(i == I && j == J) continue; //skiping curent case 
                
                if(board[I][J] == 1 || board[I][J] == 3) //considering the one that exist in the original matrix instead of the only the new ones
                    count++;
            }
                 
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ln=countNeighbours(board,i,j,m,n); 
                if(board[i][j]==0){ 
                    if(ln==3){
                        board[i][j]=2; //newly revived
                    }
                }
                else if(board[i][j]==1){
                    if(ln<2||ln>3){
                        board[i][j]=3; // newly dead
                    } 
                }
            }
        }
    for(int i=0;i<m;i++){ // final coversion
        for(int j=0;j<n;j++){
            if(board[i][j]==2) board[i][j]=1;
            else if(board[i][j]==3) board[i][j]=0;
        }
    }
    }
};