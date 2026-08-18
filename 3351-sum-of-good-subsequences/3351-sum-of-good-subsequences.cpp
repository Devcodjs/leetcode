class Solution {
public:
    #define MOD 1000000007
    int sumOfGoodSubsequences(vector<int>& nums) {
        int mx = 100001;
        vector<long long> dp(mx) , sum(mx);
        for(auto &num : nums){
            long long leftCnt = num > 0 ? dp[num - 1] : 0;
            long long leftSum = num > 0 ? sum[num - 1] : 0;

            long long rightCnt = num + 1 < mx ? dp[num + 1] : 0;
            long long rightSum = num + 1 < mx ? sum[num + 1] : 0;

            long long newCnt = (1 + leftCnt + rightCnt) % MOD;

            long long newSum = num;
            newSum = (newSum + leftSum + num * leftCnt) % MOD;
            newSum = (newSum + rightSum + num * rightCnt) % MOD;

            dp[num] = (dp[num] + newCnt) % MOD;
            sum[num] = (sum[num] + newSum) % MOD;
        }
        long long ans = 0;
        for(int i = 0 ; i < mx ; i++){
            ans = (ans + sum[i]) % MOD;
        }
        return(int) ans;
    }
};