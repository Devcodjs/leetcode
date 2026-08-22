class Solution {
    int f(int[] dp , int[] nums , int i){
        int n = nums.length;
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + f(dp , nums ,  i + 2);
        int notTake = f(dp , nums , i + 1);
        return dp[i] = Math.max(take , notTake);
    }
    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp , -1);
        return f(dp , nums , 0);
    }
}