class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        longest_seq = 0
        for num in num_set:
            if num - 1 not in num_set:
                current_num = num
                current_consec = 0
                while current_num in num_set:
                    current_consec += 1
                    current_num += 1
                longest_seq = max(longest_seq, current_consec)
        return longest_seq