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
        vector<int> dp(n + 2 , 0);
        for(int i = n - 1 ; i >= 0 ; i--){
            int onestep = cost[i] + dp[i + 1];
            int twostep = cost[i] + dp[i + 2];
            dp[i] = min(onestep , twostep);
        }
        // for(int i = n - 1 ; i >= 0 ; i--){
        //     int onestep = cost[i] + dp2[i + 1];
        //     int twostep = cost[i] + dp2[i + 2];
        //     dp2[i] = min(onestep , twostep);
        // }
        return min(dp[0] , dp[1]);
    }
};