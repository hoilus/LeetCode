class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> reslt{-1, -1};
        int ll = 0, lh = nums.size();
        while (ll < lh) {
            int mid = ll + (lh-ll)/2;
            if (nums[mid] < target)
                ll = mid + 1;
            else 
                lh = mid;
        }
        
        int hl = 0, hh = nums.size();
        while (hl < hh) {
            int mid = hl + (hh-hl)/2;
            if (nums[mid] <= target)
                hl = mid + 1;
            else
                hh = mid;
        }
        
        if (ll <= (hh-1)) {
            reslt[0] = ll;
            reslt[1] = hh-1;
        }
        return reslt;
    }
};
