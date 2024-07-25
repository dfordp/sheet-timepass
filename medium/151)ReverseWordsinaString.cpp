class Solution {
public:
    string reverseWords(string s) {
        stack<string> temp;
        string ans="";
        
        for(int i=0;i<s.size();i++){
            string word;
            if(s[i]==' ')continue;
            while(i<s.size() && s[i]!=' '){
                word+=s[i];i++;
            }
            temp.push(word);
        }

        while(!temp.empty()){
            ans+=temp.top();temp.pop();
            if(!temp.empty()) ans+=" ";
        }
        return ans;
    }
};