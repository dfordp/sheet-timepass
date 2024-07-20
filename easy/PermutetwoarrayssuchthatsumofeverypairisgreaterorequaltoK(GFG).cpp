class Solution{
    bool isPossible(vector<int>& a, vector<int>& b, int n, int k)
    {
        // Sort the array a[] in decreasing order.
        sort(a.begin(), a.end(), greater<int>());

        // Sort the array b[] in increasing order.
        sort(b.begin(), b.end(), greater<int>());
        // Checking condition on each index.
        for (int i = 0; i < a.size(); i++)
            if (a[i] + b[i] < k)
                return false;

        return true;
    }
};
