class Solution {
public:
    int f(vector<vector<vector<int>>>& dp , vector<int>& nums, int i , int buy , int k){
        int n = nums.size();
        if(i >= n) return 0;
        if(k == 0) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        int take = 0;
        if(buy == 0){
            take = max(-nums[i] + f(dp  , nums , i + 1, 1 , k) , f(dp , nums, i + 1 , 0 , k));
        }else{
            take = max(nums[i] + f(dp , nums , i + 1 , 0 , k - 1) , f(dp , nums , i + 1 , 1 , k));
        }
        int nottake = f(dp , nums , i + 1 , buy  , k);
        return dp[i][buy][k] =  take;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(2 + 1 , -1)));
        return f(dp , prices , 0 , 0 , 2);
    }
};