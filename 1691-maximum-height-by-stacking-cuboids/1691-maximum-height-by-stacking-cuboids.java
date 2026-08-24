class Solution {
    int f(int[][] dp , int[][] cuboids , int i , int prev){
        int n = cuboids.length;
        if(i >= n) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int w = cuboids[i][0] , l = cuboids[i][1] , h = cuboids[i][2];
        int take = 0;
        if(prev == -1 || cuboids[prev][0] <= w && cuboids[prev][1] <= l && cuboids[prev][2] <= h){
            take = h + f(dp , cuboids , i + 1 , i);
        }
        int notTake = f(dp , cuboids , i + 1 , prev);
        return dp[i][prev + 1] = Math.max(take , notTake);
    }
    public int maxHeight(int[][] cuboids) {
        int n = cuboids.length;
        int[][] dp = new int[n + 1][n + 1];
        for(int[] row : dp){
            Arrays.fill(row , -1);
        }
        for(int[] row : cuboids){
            Arrays.sort(row);
        }
        Arrays.sort(cuboids , (a , b)->{
            if(a[0] != b[0]) return Integer.compare(a[0] , b[0]);
            if(a[1] != b[1]) return Integer.compare(a[1] , b[1]);
            return Integer.compare(a[2] , b[2]);
        });
        return f(dp , cuboids , 0 , -1);
    }
}