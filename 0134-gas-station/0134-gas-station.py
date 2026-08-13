class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        n  , total , fuel , idx = len(gas) , 0 , 0 , 0
        for i in range(0 , n):
            diff = gas[i] - cost[i]
            total += diff
            fuel += diff
            if fuel < 0:
                fuel = 0
                idx = i + 1
        if total >= 0 : 
            return idx
        return -1
        