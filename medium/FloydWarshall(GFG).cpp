//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	      int rows = matrix.size();
          int columns = matrix[0].size();
          
               for( int k =0; k<rows; k++)
               {
                   for(int i =0; i<rows; i++)
                   {
                       for(int j =0; j<columns; j++)
                       {
                           int x = matrix[i][k];
                           int y = matrix[k][j];
                           if(x!=-1 && y!=-1)
                           {
                              if(matrix[i][j] == -1 || x+y <matrix[i][j])
                              matrix[i][j] = x+y; 
                           }
                           
                       }
                   }
               }
        }
};