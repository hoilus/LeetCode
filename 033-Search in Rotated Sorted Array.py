class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # double binary search
        # find the minimum value firstly
        # then search for the target
        n = len(nums)
        lo = 0; hi = n-1
        while(lo < hi):
            mid = int((lo + hi) / 2)
            if nums[mid] > nums[hi]:
                lo = mid + 1
            else:
                hi = mid
                
        rot = lo
        # extend the array by appending large part to the end
        lo = 0; hi = n-1
        while(lo <= hi):
            mid = int((lo + hi) / 2)
            realmid = (mid + rot) % n
            if nums[realmid] == target:
                return realmid
            if nums[realmid] > target:
                hi = mid - 1
            else:
                lo = mid + 1
        return -1
