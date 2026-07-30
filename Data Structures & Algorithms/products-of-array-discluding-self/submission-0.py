import numpy as np
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # list[start:stop:step]
        nums = np.array(nums)
        prods = [0] * len(nums)
        left_product = 1
        for i in range(len(nums)):
            prods[i] = left_product
            left_product *= nums[i]
        
        right_product = 1
        for i in range(len(nums)-1, -1, -1):
            prods[i] *= right_product
            right_product *= nums[i]

        return prods
