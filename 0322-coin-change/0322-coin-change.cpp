class Solution {
public:
    int f(vector<vector<int>>& dp, vector<int>& coins, int tar, int i) {
        int n = coins.size();
        if (tar == 0)
            return 0;
        if (i >= n)
            return 1e9;
        if (dp[i][tar] != -1)
            return dp[i][tar];
        int take = 1e9;
        if (coins[i] <= tar) {
            take = 1 + f(dp, coins, tar - coins[i], i);
        }
        int notTake = f(dp, coins, tar, i + 1);
        return dp[i][tar] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= amount ; i++){
            for(auto& c : coins){
                if(c <= i)  dp[i] = min(dp[i] , 1 + dp[i - c]);
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};