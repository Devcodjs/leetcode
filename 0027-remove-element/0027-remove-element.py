class Solution(object):
    def removeElement(self, nums, val):
        n = len(nums)
        l , r = 0 , n - 1
        while l <= r :
            if nums[l] == val:
                nums[l] , nums[r] = nums[r] , nums[l]
                r -= 1
            else:
                l += 1
        return l
        