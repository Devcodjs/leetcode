class Solution {
    int[] dr = {0 , 1 , 0  , -1};
    int[] dc = {1 , 0 , - 1, 0};
    void dfs(char[][] grid , int[][] vis , int i , int j){
        int n = grid.length;
        int m = grid[0].length;
        vis[i][j] = 1;
        for(int k = 0 ; k < 4 ; k++){
            int newr = dr[k] + i;
            int newc = dc[k] + j;

            while(newr>= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == '1' && vis[newr][newc] != 1){
                dfs(grid,  vis , newr , newc);
            }
        } 
    }

    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] vis = new int[n][m];
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1' && vis[i][j] != 1){
                    dfs(grid , vis , i , j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
}