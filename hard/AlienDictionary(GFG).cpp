// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>InDeg(K,0);
           
           vector<int>adj[K];
           for(int i=0;i<N-1;i++)
           {
               string str1=dict[i],str2=dict[i+1];
               int j=0,k=0;
               
               while(j<str1.size()&&k<str2.size()&&str1[j]==str2[k])
               k++,j++;
               if(j==str1.size())
               continue;
               
               adj[str1[j]-'a'].push_back(str2[k]-'a');
               InDeg[str2[k]-'a']++;
           }
           //apply kahn's algorithm
           
          queue<int>q;
         for(int i=0;i<K;i++)
         {
             if(!InDeg[i])
             q.push(i);
         }
         string ans;
         while(!q.empty())
         {
             int Node = q.front();
             q.pop();
             char c = 'a'+Node;
             ans+=c;
             for(int j=0;j<adj[Node].size();j++)
             {
                InDeg[adj[Node][j]]--;
                if(InDeg[adj[Node][j]]==0)
                q.push(adj[Node][j]);
             }
         }
         return ans;
    }
};