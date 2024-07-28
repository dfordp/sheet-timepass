class Solution {
    
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n);
        stack<int> stack;

        for(int i=0;i<n;i++){
            while(!stack.empty() && temperatures[stack.top()]<temperatures[i]){
                res[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        return res;
    }
};