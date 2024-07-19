class Solution {
public:
    void Nsum(std::vector<int>& nums, long long target, int N, int start, std::vector<int>& result, std::vector<std::vector<int>>& Nsums) {
        if (nums.size() < N || N < 2 || target < (long long)nums[start] * N || target > (long long)nums.back() * N)
            return;

        if (N == 2) {
            int left = start, right = nums.size() - 1;
            while (left < right) {
                long long sum = (long long)nums[left] + nums[right];
                if (sum == target) {
                    Nsums.push_back(result);
                    Nsums.back().insert(Nsums.back().end(), {nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        } else {
            for (int i = start; i < nums.size() - N + 1; i++) {
                if (i == start || (i > start && nums[i] != nums[i - 1])) {
                    result.push_back(nums[i]);
                    Nsum(nums, target - nums[i], N - 1, i + 1, result, Nsums);
                    result.pop_back();
                }
            }
        }
    }

    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> foursums;
        std::vector<int> result;
        Nsum(nums, (long long)target, 4, 0, result, foursums);
        return foursums;
    }
};
