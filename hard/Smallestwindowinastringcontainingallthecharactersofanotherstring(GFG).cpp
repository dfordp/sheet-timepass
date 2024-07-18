class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<int> freq(256, 0);
        for (char ch : p) freq[ch]++;
        
        int left = 0, right = 0, required = m, minLen = INT_MAX, minStart = 0;
        while (right < n) {
            if (freq[s[right]] > 0) required--;
            freq[s[right]]--;
            
            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0) required++;
                left++;
            }
            right++;
        }
        
        return minLen == INT_MAX ? "-1" : s.substr(minStart, minLen);
    }
};
