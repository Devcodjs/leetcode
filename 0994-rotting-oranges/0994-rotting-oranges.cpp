class Solution {
public:
    int dr[4] = {1 , 0 , -1 , 0};
    int dc[4] = {0 , -1 , 0 , 1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =  grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));
        int cnt = 0;
        int f = 0;
        queue<pair<int , int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2 ){
                    q.push({i , j});
                }else if(grid[i][j] == 1){
                    f++;
                }
            }
        }
        while(!q.empty() && f > 0){
            int sz = q.size();
            while(sz--){
                auto[i , j] = q.front();
                q.pop();
                for(int k = 0; k < 4 ; k++){
                    int newr = dr[k] + i;
                    int newc = dc[k] + j;
                    if(newr >= 0 && newc >= 0 && newr < n && newc < m && grid[newr][newc] == 1){
                        q.push({newr , newc});
                        grid[newr][newc] = 2;
                        f--;
                    }
                }
            }
            cnt++;
        }
        if(f > 0) return -1;
        return cnt;
    }
};