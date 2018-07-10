class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tmap;
        for (int i = 0; i < nums.size(); i++) {
            auto p = tmap.find(target-nums[i]);
            if (p!=tmap.end())
                return {p->second,i};
            tmap[nums[i]] = i;
        }
    }
};
