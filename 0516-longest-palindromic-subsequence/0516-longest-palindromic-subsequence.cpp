class Solution {
public:
    int f(vector<vector<int>>& dp , string& s , int i , int j){
        int n = s.size();
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = 2 + f(dp , s , i + 1 , j - 1);
        }
        return dp[i][j] = max(f(dp , s , i , j - 1) , f(dp , s , i + 1 , j));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = n - 1 ; i >= 0 ; i--){
            dp[i][i] = 1;
            for(int j = i + 1; j < n ; j++){
                if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else dp[i][j] = max(dp[i][j - 1] , dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];       
    }
};