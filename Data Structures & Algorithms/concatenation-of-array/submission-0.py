class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        n = len(nums)
        arr = [-1] * (2 * n)
        index = 0
        for i in range(len(arr)):
            if index == n:
                index = 0
            arr[i] = nums[index]
            index += 1
        return arr
