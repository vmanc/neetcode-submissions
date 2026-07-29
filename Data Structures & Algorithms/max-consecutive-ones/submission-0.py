class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = 0
        running_count = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                count+=1
                running_count = max(count, running_count)
            else:
                count = 0
        
        return running_count