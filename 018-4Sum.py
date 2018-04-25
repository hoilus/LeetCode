class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        n = len(nums)
        solution = []
        nums.sort()
        
        if n < 4:
            return solution
        
        for i in range(0, n-3):
            if (i != 0 and nums[i] == nums[i-1]):
                continue
#            if (i != 0 and nums[i] > target):
#                break
            for m in range(i+1, n-2):
                k = m + 1
                j = n - 1
                sum2 = target - nums[i] - nums[m]
                if (m != i+1 and nums[m] == nums[m-1]):
                    continue
                while (k < j):
                    tem = nums[k] + nums[j]
                    if tem > sum2:
                        j -= 1
                    elif tem < sum2:
                        k += 1
                    else:
                        solution.append([nums[i], nums[m], nums[k], nums[j]])
                        while (k < j and nums[k] == nums[k+1]):
                            k += 1
                        while (k < j and nums[j] == nums[j-1]):
                            j -= 1
                        k += 1
                        j -= 1
        return solution        
