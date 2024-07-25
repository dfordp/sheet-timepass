class Solution {
    vector<string> res;
public:
    void dfs(int left,int right,string s,int n){
        if(s.size()==2*n){
            res.push_back(s);
            return;
        }
        if(left<n){
            dfs(left+1,right,s+'(',n);
        }
        if(left>right){
            dfs(left,right+1,s+')',n);
        }
    }
     vector<string> generateParenthesis(int n) {
        dfs(0,0,"",n);
        return res;
    }
};