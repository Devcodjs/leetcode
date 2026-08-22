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
        int next = 0 , nNext = 0;
        if(n == 1) return nums[0];
        int maxi = 0;
        for(int i = n - 1 ; i >= 1 ; i--){
            int cur = 0;
            int take = nums[i] + nNext;
            int notTake = next;
            cur = max(take , notTake);
            nNext =  next;
            next = cur;
        }
        maxi = max(maxi , next);
        next = 0 , nNext = 0;
        int maxi2 = 0;
        for(int i = n - 2 ; i >= 0 ; i--){
            int cur = 0;
            int take = nums[i] + nNext;
            int notTake = next;
            cur = max(take , notTake);
            nNext = next;
            next = cur;
        }
        maxi2 = max(maxi2 , next);
        return max(maxi , maxi2);
    }
};