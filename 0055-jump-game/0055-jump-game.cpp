class Solution {
public:
    bool f(vector<int>& dp , vector<int>& nums , int i){
        int n = nums.size();
        if(i >= n - 1) return true;
        if( dp[i] != -1) return dp[i];
        if(nums[i] == 0) return dp[i] = false;
        for(int j = i + 1 ; j <= i + nums[i] ; j++){
            if(f(dp , nums , j)) return dp[i] =  true;
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        return f( dp , nums , 0);
    }
};