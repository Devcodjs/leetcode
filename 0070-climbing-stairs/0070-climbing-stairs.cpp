class Solution {
public:
    int f(vector<int>& dp , int n , int step){
        if(step >= n) return 1;
        if(dp[step] != - 1) return dp[step];
        int take1 = 0  , take2 = 0;
        take1 =  f(dp , n, step + 1);
        take2 =  f(dp , n , step + 2);
        return dp[step] = take1 + take2;
    }
    int climbStairs(int n) {
        int next = 1 , nNext = 1;
        for(int i = n - 1 ; i >= 1 ; i--){
            int cur = 0;
            cur = next + nNext;
            nNext = next;
            next = cur;
            
        }
        return next;
    }
};