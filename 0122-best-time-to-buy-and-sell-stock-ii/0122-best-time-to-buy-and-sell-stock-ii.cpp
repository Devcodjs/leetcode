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
        vector<int> cur(n + 1, 0) , next(n + 1 , 0);
        for(int i = n - 1; i >= 0 ; i--){
            for(int j = 0 ; j < 2 ; j++){
                int take = 0;
                if(j == 0){
                    take = max(-nums[i] + next[1] , next[0]);
                }else{
                    take = max(nums[i] + next[0] , next[1]);
                }
                int notTake = next[j];
                cur[j] = max(take , notTake);
            }
            next = cur;
        }
     
        return cur[0];
    }
};