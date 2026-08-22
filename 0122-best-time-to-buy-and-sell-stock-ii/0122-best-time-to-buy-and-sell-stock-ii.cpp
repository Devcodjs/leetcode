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
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1 , vector<int>(2 , 0));  
        for(int i = n - 1; i >= 0 ; i--){
            for(int j = 0 ; j < 2 ; j++){
                int take = 0;
                if(j == 0){
                    take = max(-nums[i] + dp[i + 1][1] , dp[i + 1][0]);
                }else{
                    take = max(nums[i] + dp[i+1][0] , dp[i + 1][1]);
                }
                int notTake = dp[i + 1][j];
                dp[i][j] = max(take , notTake);
            }
        }
     
        return dp[0][0];
    }
};