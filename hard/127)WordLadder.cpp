class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s {wordList.begin(),wordList.end()};
        if(!s.count(endWord)) return 0;

        unordered_set<string> q1{beginWord}, q2{endWord};
        int ladder=2;

        while(!q1.empty() && !q2.empty()){
            if (q1.size() > q2.size()) swap(q1, q2);

            unordered_set<string> temp;

            for (string w : q1) {
                for (int i = 0; i < w.size(); ++i) {
                    char c = w[i];
                    for (int j = 0; j < 26; ++j) {
                        w[i] = 'a' + j;
                        if (q2.count(w)) return ladder;
                        if (!s.count(w)) continue;
                        s.erase(w);
                        temp.insert(w);
                    }
                    w[i] = c;
                }
            }

            swap(q1, temp);
            ladder++;
        }

        return 0;
    }
};