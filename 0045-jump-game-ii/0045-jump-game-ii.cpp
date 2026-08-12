class Solution {
public:
    int f(vector<int>& dp , vector<int>& nums , int i){
        int n = nums.size();
        if(i >= n - 1) return 0;
        if( dp[i] != -1) return dp[i];
        int cnt = 1e9;
        for(int j = 1; j <= nums[i] ; j++){
            cnt = min(cnt , 1 + f(dp , nums , i + j));
        }
        return dp[i] = cnt;
    }
    int jump(vector<int>& nums) {
        int n  = nums.size();
        vector<int> dp(n , -1);
        return f(dp , nums , 0);
    }
};