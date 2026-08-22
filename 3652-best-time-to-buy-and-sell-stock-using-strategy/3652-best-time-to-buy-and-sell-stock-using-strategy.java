class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {
        int n = prices.length;
        long[] pref = new long[n + 1];
        long[] ps = new long[n + 1];
        for(int i = 0; i < n;i++){
            pref[i + 1] = pref[i] + (long) prices[i] * strategy[i];
            ps[i + 1] = ps[i] + prices[i];
        }

        int h = k / 2;
        long ans = pref[n];
        for(int i = 0 ; i + k <= n ; i++){
            int r = i + k;
            long left = pref[i];
            long mid = ps[r] - ps[r - h];
            long right = pref[n] - pref[r];

            ans = Math.max(ans , left + mid + right);
        }
        return ans;
    }
}