class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp = {}
        mp[0] = 1
        sumi = 0
        ans = 0
        for i in range(0 , len(nums)):
            sumi += nums[i]
            tar = sumi - k
            if tar in mp :
                ans += mp[tar]
            mp[sumi] = mp.get(sumi , 0) + 1
        return ans
        