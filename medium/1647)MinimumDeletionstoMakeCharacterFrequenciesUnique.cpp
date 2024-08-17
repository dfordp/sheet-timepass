class Solution {
public:
    int minDeletions(string s) {
         //Array to store the count of each character.
        vector<int> freq (26, 0);
        
        //Calculatimg frequency of all characters.
        for (char c : s){
            freq[c - 'a']++;
        }
        
        //sorting the frequencies. So the greatest frequencies are in right side.
        sort(freq.begin(), freq.end());
        
        int del = 0; //to store the deletions.
    
        for (int i = 24; i >= 0; i--) {
            
            if(freq[i] >= freq[i+1]){
                int prev = freq[i]; //To store the frequency before deletion.
                freq[i] = max(0, freq[i+1] -1); //New frequency should be 1 less than the previous frequency in the array.
                del += prev - freq[i]; //Calculating deleted characters 
            }
        }
        return del;
    }
};