class Solution(object):
    def productExceptSelf(self, nums):
        n = len(nums)
        ans = [1] * n
        prod = nums[0]
        for i in range(1 , n):
            ans[i] = prod
            prod *= nums[i]
        
        prod = nums[n - 1]
        for i in range(n - 2 , -1 , -1):
            ans[i] = ans[i] * prod
            prod *= nums[i]
        return ans
        
        