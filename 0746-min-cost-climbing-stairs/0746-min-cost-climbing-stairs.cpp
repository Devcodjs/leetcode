class Solution {
public:
    int f(vector<int>& dp , vector<int>& cost , int i){
        int n = cost.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int onestep = cost[i] + f(dp , cost , i + 1);
        int twostep = cost[i] + f(dp , cost , i + 2);
        return dp[i] = min(onestep , twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int next = 0; int nNext = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            int cur = 0;
            int onestep = cost[i] + next;
            int twostep = cost[i] + nNext;
            cur = min(onestep , twostep);
            nNext = next;
            next = cur;
        }
        return min(next , nNext);
    }
};