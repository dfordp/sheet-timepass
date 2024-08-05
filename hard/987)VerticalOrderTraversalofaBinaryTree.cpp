class Solution {
public:
    void FindAnswer(TreeNode* root, int currentX, int currentY, map<int, vector<pair<int,int>>>& resMap){
        if(root == NULL)
            return;

        FindAnswer(root->left, currentX - 1, currentY - 1, resMap);
         if(resMap.find(currentX) == resMap.end())
        {
            resMap[currentX] = vector<pair<int,int>>(1, pair<int,int>(currentY, root->val));
        }
        else
        {
            resMap[currentX].push_back(pair<int,int>(currentY, root->val));
            sort(resMap[currentX].begin(), resMap[currentX].end(), [](const pair<int,int>& v1, const pair<int,int>& v2) {
                if(v1.first == v2.first)
                    return v1.second < v2.second;
                return v1.first > v2.first;
            });
        }
        FindAnswer(root->right, currentX + 1, currentY - 1, resMap);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;                   
        map<int, vector<pair<int,int>>> resMap;

          
        FindAnswer(root, 0, 0, resMap);

        for(pair<int, vector<pair<int,int>>> x : resMap){
            vector<int> resPartial;
            
            for(pair<int,int> partial : x.second)
                resPartial.push_back(partial.second);
            
            res.push_back(resPartial);    
        }
        
        return res;
    }
};