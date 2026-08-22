class Solution {
    int f(int[] dp, int[] nums, int i) {
        int n = nums.length;
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int take = nums[i] + f(dp, nums, i + 2);
        int notTake = f(dp, nums, i + 1);
        return dp[i] = Math.max(take, notTake);
    }

    public int rob(int[] nums) {
        int n = nums.length;
        int next = 0 , nNext = 0;
        for (int i = n - 1; i >= 0; i--) {
            int cur = 0;
            int take = nums[i] + nNext;
            int notTake = next;
            cur = Math.max(take, notTake);
            nNext = next;
            next = cur;
        }

        return next;
    }
}