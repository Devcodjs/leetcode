class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        mp = {}
        for e in nums:
            mp[e] = mp.get(e , 0)+1
        ans = [[] for _ in range(n + 1)] 
        for key , val in mp.items():
            ans[val].append(key)
        
        res = []
        for i in range(n , -1  , -1):
            for j in ans[i]:
                if k > 0:
                    res.append(j)
                    k -= 1
                    if k == 0:break
        return res