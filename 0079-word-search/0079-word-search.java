class Solution {
    int[] dr = {1 , 0 , - 1 , 0};
    int[] dc = {0 , - 1 , 0 , 1};
    boolean dfs(char[][] board ,int[][] vis ,  String s , int i , int j , int t){
        int n = board.length;
        int m = board[0].length;
        if(t >= s.length()) return true;
        vis[i][j] = 1;
        if(i < 0 && i >= n && j < 0 && j >= m ) return false;  
        for(int k = 0 ; k < 4 ; k++){
            int r = dr[k] + i;
            int c = dc[k] + j;
            if(r >= 0 && r < n && c >= 0 &&  c < m && board[r][c] == s.charAt(t) && vis[r][c] == 0){
                if(dfs(board , vis , s , r , c , t + 1)) return true;
            }
        } 
        vis[i][j] = 0;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        int n = board.length;
        int m = board[0].length;
        int [][] vis = new int[n][m];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word.charAt(0)){
                    if(dfs(board , vis , word , i , j , 1)) return true;
                }
            }
        }
        return false;
    }
}