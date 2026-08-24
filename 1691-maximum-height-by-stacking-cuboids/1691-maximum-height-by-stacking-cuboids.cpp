class Solution {
public:
    int f(vector<vector<int>>& dp , vector<vector<int>>& cuboids , int i , int prev){
        int n = cuboids.size();
        if(i  >= n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int w1 = cuboids[i][0] ,  l1 = cuboids[i][1] , h1 = cuboids[i][2];
        int take = 0;
        if(prev == -1 || (cuboids[prev][0] <= w1 && cuboids[prev][1] <= l1 && cuboids[prev][2] <= h1)){
            take = h1 + f(dp , cuboids , i + 1 , i);
        }
        int notTake = f(dp , cuboids , i + 1 , prev);
        return dp[i][prev+1] = max(take , notTake); 
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(auto& e : cuboids){
            sort(begin(e) , end(e));
        }
        sort(cuboids.begin() , cuboids.end()); 
        vector<vector<int>>dp(n + 1 , vector<int>(n + 1 , -1));
        return f(dp , cuboids , 0 , -1);
    }
};