class Solution {
public:
    int f(vector<int>& dp , vector<int>& nums , int i , int end){
        if(i > end) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + f(dp , nums , i + 2 , end);
        int notTake = f(dp , nums  , i + 1 , end);
        return dp[i] = max(take , notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n   , -1) , dp2(n  , -1);
        if(n == 1) return nums[0];
        int maxi1 = f(dp1 , nums , 1 , n - 1);
        int maxi2 = f(dp2 , nums  , 0 , n - 2);
        return max(maxi1 , maxi2);
    }
};