class Solution {
public:
    #define MOD 1000000007
    int sumOfGoodSubsequences(vector<int>& nums) {
        int mx = 100001;
        vector<long long> dp(mx) , sum(mx);
        for(auto &num : nums){
            long long cnt = 1;
            long long s = num;

            if(num - 1 >= 0){
                cnt = (cnt + dp[num - 1]) % MOD;
                s = (s + sum[num - 1] + (num * dp[num - 1]) % MOD) % MOD;
            }

            if(num + 1 < mx){
                cnt = (cnt + dp[num + 1]) % MOD;
                s = (s + sum[num + 1] + (num * dp[num + 1]) % MOD) % MOD;
            }

            dp[num] = (dp[num] + cnt) % MOD;
            sum[num] = (sum[num] + s) % MOD;
        }
        long long ans = 0;
        for(int i = 0 ; i < mx ; i++){
            ans = (ans + sum[i]) % MOD;
        }
        return(int) ans;
    }
};