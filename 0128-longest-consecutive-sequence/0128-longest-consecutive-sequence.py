class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        st = set(nums)
        maxi = 0
        for x in st:
            if (x - 1) not in st:
                cur , lenght = x , 0
                while cur in st:
                    cur += 1
                    lenght += 1
                maxi = max(maxi , lenght)
        return maxi



        