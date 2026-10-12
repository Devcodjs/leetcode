class Solution(object):
    def twoSum(self, nums, target):
        n = len(nums)
        mp = {}
        for i in range(0 , n):
            d = target - nums[i]
            if d in mp:
                return [i , mp[d]]
            mp[nums[i]] = i
        return [-1 , -1]
        