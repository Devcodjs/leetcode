class Solution {
public:
    int f(vector<vector<vector<int>>>& dp, vector<int>& nums, int i, int buy,
          int k) {
        int n = nums.size();
        if (i >= n)
            return 0;
        if (k == 0)
            return 0;
        if (dp[i][buy][k] != -1)
            return dp[i][buy][k];
        int take = 0;
        if (buy == 0) {
            take = max(-nums[i] + f(dp, nums, i + 1, 1, k),
                       f(dp, nums, i + 1, 0, k));
        } else {
            take = max(nums[i] + f(dp, nums, i + 1, 0, k - 1),
                       f(dp, nums, i + 1, 1, k));
        }
        return dp[i][buy][k] = take;
    }
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2 + 1, 0)));
        for (int i = n - 1; i>= 0; i--) {
            for (int j = 0; j < 2; j++) {
                for (int k = 1; k <= 2; k++) {
                    int take = 0;
                    if (j == 0) {
                        take = max(-nums[i] + dp[i + 1][1][k], dp[i+1][0][k]);
                    } else {
                        take = max(nums[i] + dp[i+1][0][k-1], dp[i+1][1][k]);
                    }
                    dp[i][j][k] = take;
                }
            }
        }
        return dp[0][0][2];
    }
};