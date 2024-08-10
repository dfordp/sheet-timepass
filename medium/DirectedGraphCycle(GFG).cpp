class Solution {
  public:
    bool fun(int i,vector<int> adj[],vector<bool> &vis1,vector<bool> &vis2){
        vis1[i]=true;
        vis2[i]=true;
        
        for(auto z:adj[i]){
            if(!vis1[z]){
                if(fun(z,adj,vis1,vis2))
                    return true;
            }
            else if(vis2[z])
                return true;
            
        }
        vis2[i]=false;
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis1(V,false);
        vector<bool> vis2(V,false);
          
        for(int i=0;i<V;i++){
            if(!vis1[i]){
                if(fun(i,adj,vis1,vis2))
                    return true;    
            }
            
        }  
        return false; 
    }
};