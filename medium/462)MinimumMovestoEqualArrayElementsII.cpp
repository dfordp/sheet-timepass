class Solution {
public:
    int minMoves2(vector<int>& n) {
        int c=0;
        sort(n.begin(),n.end());
        int m=n.size();
        int mid=m/2;
        for(int i=1;i<m;i++)
        {
          for (i = 0; i < m; i++)
            c += abs (n[i] - n[mid]);
        }
        return c;
    }
};