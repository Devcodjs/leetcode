class Solution {
    int f(int[][][] dp , int[] nums , int i , int buy , int k){
        int n = nums.length;
        if(i >= n) return 0;
        if(k == 0) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        int take = 0;
        if(buy == 0){
            take  = Math.max(-nums[i] + f(dp , nums , i + 1 , 1 , k) , f(dp, nums , i + 1 , 0 , k));
        }else{
            take = Math.max(nums[i] + f(dp , nums , i + 1 , 0 , k - 1) , f(dp , nums , i + 1 , 1 , k));
        }
        return dp[i][buy][k] = take;
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][][] dp = new int[n][2][3] ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0  ; j < 2 ; j++){
                Arrays.fill(dp[i][j] , -1);
            }
        }
        return f(dp , prices , 0 , 0 , 2);
    }
}