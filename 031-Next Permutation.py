class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        switch = False
        action = False
        for i in range(n-2,-1,-1):
            if (nums[i] < nums[i+1]):
                switch = True
                break
        if switch == False:
            nums.reverse()
        else:
            for j in range(i+1,n-1,1):
                if nums[j] > nums[i] and nums[i] >= nums[j+1]:
                    nums[j], nums[i] = nums[i], nums[j]
                    action = True
                    break
            if action == False:
                nums[n-1], nums[i] = nums[i], nums[n-1]
            nums[(i+1):] = reversed(nums[(i+1):])
