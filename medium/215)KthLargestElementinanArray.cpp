class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto compare = [](const int& a, const int& b) { return a > b; };
        priority_queue<int,vector<int>,decltype(compare)> min_heap(nums.begin(),nums.begin()+k);

        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        
        return min_heap.top();
    }
};