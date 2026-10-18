class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        n = len(nums)
        l = 0
        for i in range(0 , n):
            if nums[i] == 0: continue
            else :
                nums[l] , nums[i]  = nums[i] , nums[l]
                l += 1
            
        for i in range(l + 1 , n):
            nums[i] = 0
        