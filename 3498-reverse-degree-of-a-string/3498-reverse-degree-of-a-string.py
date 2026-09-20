class Solution:
    def reverseDegree(self, s: str) -> int:
        n = len(s)
        sumi = 0
        for i in range(n):
            revidx = 26 - (ord(s[i]) - ord('a'))
            sumi += revidx * (i + 1)
        return sumi
        