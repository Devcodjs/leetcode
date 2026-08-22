class Solution {
public:
    int f(vector<vector<int>>& dp , vector<int>& nums,  int i , int buy){
        int n = nums.size();
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int take = 0;
        if(buy == 0){
            take = max(-nums[i] + f(dp , nums , i + 1 , 1)  , f(dp , nums, i +1 , 0));
        }else{
            take = max(nums[i] + f(dp , nums , i + 1 , 0) , f(dp , nums, i+ 1 , 1));
        }
        int notTake = f(dp , nums , i + 1 , buy);
        return dp[i][buy] = max(take , notTake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2 , -1));
        return f(dp , prices , 0 , 0);
    }
};