class Solution(object):
    def isAnagram(self, s, t):
        n = len(s)
        m = len(t)
        if n != m : return False
        mp1 , mp2 = {} , {}
        for i in range(0 , n):
            mp1[s[i]]  = mp1.get(s[i] , 0) + 1
            mp2[t[i]]  = mp2.get(t[i] , 0) + 1
        return mp1 == mp2
        