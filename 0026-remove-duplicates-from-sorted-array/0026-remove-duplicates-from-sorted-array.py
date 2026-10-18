class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        n = len(nums)
        i , j = 0 , 0
        while j < n:
            if nums[i] != nums[j]:
                i += 1
                nums[i] , nums[j] = nums[j] , nums[i]
            j += 1
        return i + 1
        