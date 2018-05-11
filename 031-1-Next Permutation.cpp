class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), j = n-2;
        if (n < 2) return;
        while(j >= 0 && nums[j] >= nums[j+1]) j--;
        
        if (j < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        int i = j+1;
        while (i < n && nums[i] > nums[j]) i++;
        i--;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin()+j+1, nums.end());
    }
};
