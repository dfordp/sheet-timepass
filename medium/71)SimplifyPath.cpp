class Solution {
public:
    string simplifyPath(string path) {
        string res;

        stack<string> st;

        //push the words into the stack
        for(int i=0;i<path.size();i++){
            
            if(path[i]=='/'){
                continue;
            }

            string temp;

            //iterate till we doesn't traverse the whole string & doesn't encounter the last /

             while(i < path.size() && path[i] != '/')
            {
				// add path to temp string
                temp += path[i];
                ++i;
            }

            if(temp == ".")
                continue;

            // pop the top element from stack if exists
            else if(temp == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
            //push the word from the string

                st.push(temp);
        }

        // adding all the stack elements to res
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }

        // if no directory or file is present
        if(res.size() == 0)
            return "/";
        
        return res;
    }
};