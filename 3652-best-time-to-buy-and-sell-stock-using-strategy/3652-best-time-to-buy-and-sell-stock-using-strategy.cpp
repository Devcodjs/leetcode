class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> pref( n + 1, 0) , ps(n + 1 , 0);
        for(int i = 1 ; i <= n ; i++){
            pref[i] = pref[i - 1] + 1LL* (prices[i-1] * strategy[i-1]);
            ps[i] = ps[i - 1] + prices[i - 1];
        }
        long long ans = pref[n];
        int h = k / 2;

        for(int i = 0 ; i + k <= n ; i++){
            int r = i +  k;
            long long left = pref[i];
            long long mid = ps[r] - ps[i + h];
            long long right = pref[n] - pref[r];
            ans = max(ans , left + mid + right);
        }
        return ans;
    }
};