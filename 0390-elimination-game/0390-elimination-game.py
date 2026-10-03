class Solution(object):
    def lastRemaining(self, n):
        step , pos , isSt = 1 , 1 , True
        while n > 1 :
            if isSt or n % 2 == 1:
                pos += step
            n = n // 2
            step *= 2
            isSt = not isSt
        return pos

        