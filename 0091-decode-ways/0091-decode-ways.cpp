class Solution {
public:
    int f(vector<int>& dp , string s , int i){
        int n = s.size();
        if(i >= n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        int take1 = 0 , take2 = 0;
        int sum = 0;
        if(i + 1 < n ){
            sum += (s[i] - '0') * 10 + (s[i + 1] - '0');
        }
        take1 = f(dp , s , i + 1);
        if(sum > 9  && sum <= 26){
            take2 = f(dp , s , i + 2);
        }
        return dp[i] = take1 + take2;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 2 , 0);
        dp[n] = 1;
        dp[n + 1] = 1;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(s[i] == '0') continue;
            int take1 = 0 , take2 = 0;
            int sum = 0;
            if(i + 1 < n ){
                sum += (s[i] - '0') * 10 + (s[i + 1] - '0');
            }
            take1 = dp[i + 1];
            if(sum > 9  && sum <= 26){
                take2 = dp[i + 2];
            }
            dp[i] = take1 + take2;
        }
        return dp[0];
    }
};