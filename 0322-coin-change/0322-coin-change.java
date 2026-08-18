class Solution {
    int f(int[][] dp ,int[] coins , int amount , int i){
        int n = coins.length;
        if(i >= n) return (int)1e9;
        if(amount == 0) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        int take = (int)1e9;
        if(amount >= coins[i]){
            take = 1 + f(dp , coins , amount - coins[i] , i);
        }
        int notTake = f(dp , coins , amount , i + 1);
        return dp[i][amount] = Math.min(take,  notTake);
    }
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int[][] dp = new int[n][amount + 1];
        for(int [] row : dp){
            Arrays.fill(row , -1);
        }
        int ans = f(dp ,coins , amount , 0);
        return ans == (int)1e9 ? -1 : ans;
    }
}