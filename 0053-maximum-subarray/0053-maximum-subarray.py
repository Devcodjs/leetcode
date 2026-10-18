class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        maxi , sumi = float('-inf') , 0
        for i in range(0 , n):
            if sumi < 0: sumi = 0
            sumi += nums[i]
            maxi = max(maxi, sumi)
        return maxi
        