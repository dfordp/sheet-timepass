class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> set;
        for(int x:nums){
            if(set.find(x)!=set.end()){
                ans.push_back(x);
            }
            else{
                set.insert(x);
            }
        }
        return ans;
    }
};