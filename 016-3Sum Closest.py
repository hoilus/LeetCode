class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        """
        n = len(nums)
        nums.sort()
        solution = nums[0] + nums[1] + nums[2]
        
        for i in range(0, n-2):
            k = i + 1
            j = n - 1

            if (nums[i] > target):
                break

            while (k < j):
                tmp = nums[i] + nums[k] + nums[j]
                if tmp > target:
                    j -= 1
                elif tmp < target:
                    k += 1
                else:
                    return target
                
                if abs(tmp - target) < abs(solution - target):
                    solution = tmp
                
        return solution                
        
        """

    
        nums.sort()
        result = nums[0] + nums[1] + nums[2]
        for i in range(len(nums) - 2):
            j, k = i+1, len(nums) - 1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum == target:
                    return sum
                
                if abs(sum - target) < abs(result - target):
                    result = sum
                
                if sum < target:
                    j += 1
                elif sum > target:
                    k -= 1
            
        return result
