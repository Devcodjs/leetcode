class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        n = len(strs)
        mini = float('inf')
        for i in strs:
            mini = min(mini , len(i))
        
        t = ""
        for i in range(0 , mini):
            c = strs[0][i]
            for j in range(0 , n):
                if c != strs[j][i]: return t
            t += c
        return t