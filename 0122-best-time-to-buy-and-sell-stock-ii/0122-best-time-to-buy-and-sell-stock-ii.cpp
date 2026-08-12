class Solution {
public:
    int f(vector<vector<int>>& dp, vector<int>& prices, int i,
          int turn) { // turn -> 0 = buy , 1 ->
        int n = prices.size();
        if (i >= n)
            return 0;
        if (dp[i][turn] != -1)
            return dp[i][turn];
        int take = 0;
        if (turn == 0) {
            take = max(-prices[i] + f(dp, prices, i + 1, 1),
                       f(dp, prices, i + 1, 0));
        } else {
            take = max(prices[i] + f(dp, prices, i + 1, 0),
                       f(dp, prices, i + 1, 1));
        }
        return dp[i][turn] = take;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i][0] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);
           
            dp[i][1] = max(prices[i] + dp[i + 1][0], dp[i + 1][1]);
            
        }
        return dp[0][0];
    }
};