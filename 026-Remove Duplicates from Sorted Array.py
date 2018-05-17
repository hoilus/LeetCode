class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0 or n == 1:
            return n
        result = 0
        for i in range(n-1):
            if nums[-i-1+result] == nums[-i-2+result]:
                nums.pop(n-i-1)
                result += 1
        return n - result
