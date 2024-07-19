class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int a=strs.size();
        sort(strs.begin(),strs.end()); 
        string n=strs[0]; 
        string m=strs[a-1];
        string ans="";
        for (int i=0;i<n.size();i++){
            if(n[i]==m[i])ans+=n[i];
            else break;
        }
        return ans;
    }
};