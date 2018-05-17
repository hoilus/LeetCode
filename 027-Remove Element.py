class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return n
        result = 0
        for i in range(n):
            if nums[-i-1+result] == val:
                nums.pop(n-i-1)
                result += 1
        return n - result
