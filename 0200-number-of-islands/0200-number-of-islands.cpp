class Solution {
public:
    int dr[4] = {0 , 1 , 0 , -1};
    int dc[4] = {1 , 0 , -1 , 0};
    void dfs(vector<vector<char>>& grid , vector<vector<int>>& vis , int i , int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 && i >= n && j < 0 && j >= m) return ;
        vis[i][j] = 1;
        for(int k = 0; k < 4 ; k++){
            int newr = dr[k] + i;
            int newc = dc[k] + j;
            while(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == '1' && !vis[newr][newc]){
                vis[newr][newc] = 1;
                dfs(grid , vis , newr , newc);
            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n , vector<int>(m  , 0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid , vis , i , j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};