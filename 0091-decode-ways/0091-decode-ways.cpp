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
        int next =  1; //dp[n] = 1;
        int nNext = 1 ; //dp[n + 1] = 1;
        for(int i = n - 1 ; i >= 0 ; i--){
            int cur = 0;
            if(s[i] == '0') {
                nNext = next;
                next = cur;
                continue;
            }
            int take1 = 0 , take2 = 0;
            int sum = 0;
            if(i + 1 < n ){
                sum += (s[i] - '0') * 10 + (s[i + 1] - '0');
            }
            take1 = next;
            if(sum > 9  && sum <= 26){
                take2 = nNext;
            }
            cur = take1 + take2;
            nNext = next;
            next = cur;
        }
        return next;
    }
};