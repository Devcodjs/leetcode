class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pos , neg = 0 , 1
        ans = [0] * n
        for i in range(0 , n):
            if nums[i] > 0 :
                ans[pos] = nums[i]
                pos += 2
            else :
                ans[neg] = nums[i]
                neg += 2
        return ans