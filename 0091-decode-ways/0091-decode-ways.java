class Solution {
    int f(int[] dp , String s , int i){
        int n = s.length();
        if(i >= n) return 1;
        if(dp[i] != -1) return dp[i];
        int take1 = 0 , take2 = 0;
        if(s.charAt(i) == '0') return 0;
        int sum = 0;
        if(i + 1 < n){
            sum = (s.charAt(i) - '0') * 10 + (s.charAt(i+1) - '0');
        }
        take1 = f(dp , s , i + 1);
        if(sum > 9 && sum <= 26)take2 = f(dp , s , i + 2);
        return dp[i] = take1 + take2;
    }
    public int numDecodings(String s) {
        int n = s.length();
        int[] dp = new int[n];
        Arrays.fill(dp , -1);
        return f(dp , s , 0);
    }
}