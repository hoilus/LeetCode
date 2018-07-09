class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        for (auto iter = nums.begin()+1; iter != nums.end(); ++iter)
            if (*iter == *(iter-1)) {
                iter = nums.erase(iter);
                --iter;
            }
        return nums.size();
    }
};
