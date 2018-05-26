class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto bound = equal_range(nums.begin(), nums.end(), target);
        if (bound.first == bound.second)
            return {-1, -1};
        return {bound.first - nums.begin(), bound.second - nums.begin() - 1};
    }
};
