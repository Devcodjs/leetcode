class Solution {
public:
    int f(vector<vector<int>>& dp , vector<int>& cost , int i , int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int ind = i ; ind <= j ; ind++){
            int c = cost[j + 1] - cost[i-1] + f(dp , cost , i , ind - 1) + f(dp , cost , ind + 1 , j);
            mini = min(mini , c);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts) , end(cuts));
        int c = cuts.size();
        vector<vector<int>> dp(c , vector<int>(c , -1));
        return f(dp , cuts , 1 , c - 2);
    }
};