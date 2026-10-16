class Solution:
    def countPrimes(self, n: int) -> int:
        arr = [False] * n
        cnt = 0
        if n <= 2 : return 0
        for i in range(2 , int(math.sqrt(n)) + 1 ):
            if arr[i] == False :
                j = i * i
                while j < n:
                    arr[j] = True
                    j = j + i
        for i in range(2 , n):
            if arr[i] == False : cnt += 1
        
        return cnt

