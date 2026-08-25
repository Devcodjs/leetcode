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
        vector<int> dp1(n  , -1) , dp2(n , -1);
        return min(f(dp1 , cost , 0) , f(dp2 , cost , 1));
    }
};