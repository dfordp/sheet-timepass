class Solution {
    vector<vector<int>> ans;
public:

    void helper(int index,int k,vector<int>&current,int n){
        if(current.size()==k){
            ans.push_back(current);
            return;
        }

        for(int i=index;i<=n;i++){
            current.push_back(i);
            // for(int x:current){
            //     cout<<x<<endl;
            // }
            // cout<<endl;
            helper(i+1,k,current,n);
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        helper(1,k,current,n);
        return ans;
    }
};