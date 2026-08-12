class Solution:
    def hIndex(self, c: List[int]) -> int:
        n = len(c)
        c.sort()
        ans = 0
        for i in range(0 , n):
            p = n - i
            if c[i] >= p:
                ans = max(ans , p)
        return ans
        