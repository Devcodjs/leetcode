class Solution:
    def largestOddNumber(self, num: str) -> str:
        n = len(num)
        while n >= 0:
            i = int(num[n - 1])
            if i % 2 != 0:
                return num[0 : n]
            n -= 1
        return ""