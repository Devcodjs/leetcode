class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        int[] cur = new int[n + 1];
        int[] next = new int[n + 1];
        for(int i = n - 1 ; i >= 0 ; i--){
            cur[i] = 1;
            for(int j = i + 1 ; j < n ; j++){
                if(s.charAt(i) == s.charAt(j)){
                    cur[j] = 2 + next[j - 1];
                }else{
                    cur[j] = Math.max(cur[j - 1] , next[j]);
                }
            }
            next = cur.clone();
        }
        return cur[n - 1];
    }
}