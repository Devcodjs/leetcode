class Solution(object):
    def hIndex(self, c):
        n = len(c)
        c.sort()
        ans = 0
        for i in range(0 , n):
            p = n - i
            if c[i] >= p:
                ans = max(ans , p)
        return ans
        