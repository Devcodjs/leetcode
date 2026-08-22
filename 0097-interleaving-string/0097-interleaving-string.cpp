class Solution {
public:
    int f(vector<vector<int>>& dp, string s1, string s2, string s3, int i,
          int j) {
        int n = s1.size(), m = s2.size();
        if (i == n && j == m)
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];
        bool take = false, notTake = false;
        int k = i + j;
        if (i < n && s1[i] == s3[k]) {
            take = f(dp, s1, s2, s3, i + 1, j);
        }
        if (j < m && s2[j] == s3[k]) {
            notTake = f(dp, s1, s2, s3, i, j + 1);
        }
        return dp[i][j] = take || notTake;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), t = s3.size();
        if (n + m != t)
            return false;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[n][m] = 1;
        for (int i = m - 1; i >= 0; i--) {
            dp[n][i] = (s3[n + i] == s2[i]) && dp[n][i + 1];
        }
        for (int i = n - 1; i >= 0 ; i--) {
            dp[i][m] = (s3[m + i] == s1[i]) && dp[i + 1][m];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                bool take = false, notTake = false;
                int k = i + j;
                if ( s1[i] == s3[k]) {
                    take = dp[i + 1][j];
                }
                if (s2[j] == s3[k]) {
                    notTake = dp[i][j + 1];
                }
               dp[i][j] = take || notTake;
            }
        }
        return dp[0][0];
    }
};