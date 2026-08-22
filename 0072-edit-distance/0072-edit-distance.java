class Solution {
    int f(int[][] dp , String s , String t , int i , int j){
        int n = s.length() , m = t.length();
        if(i >= n){
            return j < m ? m - j : 0;
        }
        if(j >= m){
            return  i < n ? n - i : 0;
        }

        if(dp[i][j] != -1) return dp[i][j];
        int cnt1 = 0 ,  cnt2 = 0 , cnt3 = 0;
        if(s.charAt(i) == t.charAt(j)) return dp[i][j] = f(dp , s , t , i + 1 , j + 1);
        else{
            // replace the char...
            cnt1 = 1 + f(dp , s , t , i + 1, j + 1);

            // delete the char...
            cnt2 = 1 + f(dp , s , t , i + 1 , j);

            // add the char...
            cnt3 = 1 + f(dp , s , t , i , j + 1);
        }
        return dp[i][j] = Math.min(cnt1 , Math.min(cnt2 , cnt3));
    }
    public int minDistance(String word1, String word2) {
        int n = word1.length() , m = word2.length();
        int[][] dp =  new int[n][m];
        for(int  i = 0 ; i < n ; i++){
            Arrays.fill(dp[i] , -1);
        }
        return f(dp , word1 , word2 , 0 , 0);
    }
}