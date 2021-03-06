class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        solution = []
        nums.sort()
        
        if n < 3:
            return solution
        
        for i in range(0, n-2):
            k = i + 1
            j = n - 1
            sum2 = 0 - nums[i]
            if (i != 0 and nums[i] == nums[i-1]):
                continue
            if (nums[i] > 0):
                break
            while (k < j):
                if (k != i+1 and nums[k] == nums[k-1]):
                    k += 1
                    continue
                if (j != n-1 and nums[j] == nums[j+1]):
                    j -= 1
                    continue
                tem = nums[k] + nums[j]
                if tem > sum2:
                    j -= 1
                elif tem < sum2:
                    k += 1
                else:
                    solution.append([nums[i], nums[k], nums[j]])
                    k += 1
                    j -= 1
        return solution
