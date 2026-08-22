class Solution {
    int f(int[] dp , int[] nums , int i , int end){
        if(i > end) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + f(dp , nums , i + 2 , end);
        int notTake = f(dp , nums , i + 1 , end);
        return dp[i] = Math.max(take , notTake);
    }
    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp1 = new int[n];
        Arrays.fill(dp1 , -1);
        int[] dp2 = new int[n];
        Arrays.fill(dp2 , -1);
        if(n == 1) return nums[0];
        int maxi1 = f(dp1 , nums , 1 , n - 1);
        int maxi2 = f(dp2 , nums , 0 , n - 2);
        return Math.max(maxi1 , maxi2);
    }
}