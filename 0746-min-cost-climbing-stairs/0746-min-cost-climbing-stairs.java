class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int next = 0 , nNext = 0;
        for(int i =  n - 1 ; i >= 0 ; i--){
            int cur = 0;
            cur = Math.min(cost[i] + next , cost[i] + nNext);
            nNext = next;
            next = cur;
        }
        return Math.min(next , nNext);
    }
}