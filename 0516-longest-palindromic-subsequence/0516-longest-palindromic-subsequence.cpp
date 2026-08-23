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
        vector<int> cur(n +  1 , 0) , next(n + 1 , 0);
        for(int i = n - 1 ; i >= 0 ; i--){
            cur[i] = 1;
            for(int j = i + 1; j < n ; j++){
                if(s[i] == s[j]){
                    cur[j] = 2 + next[j - 1];
                }
                else cur[j] = max(cur[j - 1] , next[j]);
            }
            next = cur;
        }
        return cur[n - 1];       
    }
};