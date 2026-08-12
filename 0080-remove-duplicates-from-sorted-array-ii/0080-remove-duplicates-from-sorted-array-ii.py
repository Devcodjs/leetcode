class Solution(object):
    def removeDuplicates(self, nums):
        n = len(nums)
        j = 0
        for i in range(0 , n):
            if j  < 2 or nums[i] != nums[j-2]:
                nums[j] = nums[i]
                j += 1
        return j