class Solution {
public:
    int f(vector<vector<int>>& dp , string& s , string& t ,  int i , int j){
        int n = s.size();
        if(i == n || j == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take = 0;
        if(s[i] == t[j]) take = 1 + f(dp , s , t  , i + 1 , j + 1);
        int notTake = max(f(dp , s , t , i + 1 , j) , f(dp , s , t , i , j + 1));
        return dp[i][j] = max(take , notTake);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        string t = s;
        reverse(begin(t) , end(t));
        return f(dp , s , t , 0 , 0);       
    }
};