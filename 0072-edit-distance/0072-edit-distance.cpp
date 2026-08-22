class Solution {
public:
    int f(vector<vector<int>>& dp, string& s, string& t, int i, int j) {
        int n = s.size(), m = t.size();
        if (i >= n) {
            return j < m ? m - j : 0;
        }
        if (j >= m) {
            return i < n ? (n - i) : 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        if (s[i] == t[j])
            return dp[i][j] = f(dp, s, t, i + 1, j + 1);
        else {
            // replace the char..
            cnt1 = 1 + f(dp, s, t, i + 1, j + 1);

            // delete the char...
            cnt2 = 1 + f(dp, s, t, i + 1, j);

            // add the char....
            cnt3 = 1 + f(dp, s, t, i, j + 1);
        }
        return dp[i][j] = min({cnt1, cnt2, cnt3});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> cur(m + 1 , 0) , next(m + 1 , 0);
        for(int j = 0 ; j <= m ; j++){
            cur[j] = m - j;
            next[j] = m - j;
        }
        for (int i = n - 1; i >= 0; i--) {
            cur[m] = n - i;
            for (int j = m - 1; j >= 0; j--) {
                int cnt1 = 0, cnt2 = 0, cnt3 = 0;
                if (word1[i] == word2[j])
                    cur[j] = next[j+1];
                else {
                    // replace the char..
                    cnt1 = 1 + next[j+1];

                    // delete the char...
                    cnt2 = 1 +  next[j];

                    // add the char....
                    cnt3 = 1 + cur[j+1];
                    cur[j] = min({cnt1, cnt2, cnt3});
                }
            }
            next = cur;
        }
        return cur[0];
    }
};