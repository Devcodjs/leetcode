class Solution {
    public int orangesRotting(int[][] grid) {
        int n = grid.length , m = grid[0].length;
        Queue<int[]> q = new  LinkedList<>();
        int[] dr = {1 , 0 , -1 ,0};
        int[] dc = {0 , -1 , 0, 1};
        int f = 0 , ans = 0;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.offer(new int[]{i , j});
                }else if(grid[i][j] == 1) f++;
            }
        }
        while(!q.isEmpty() && f > 0){
            int sz = q.size();
            while(sz--> 0){
                int i = q.peek()[0];
                int j = q.peek()[1];
                q.poll();
                for(int k = 0 ; k < 4 ; k++){
                    int r = dr[k] + i;
                    int c = dc[k] + j;
                    if(r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1){
                        grid[r][c]  = 2;
                        f--;
                        q.offer(new int[]{r , c});
                    }
                }
            }
            ans++;
        }
        if(f > 0) return -1;
        return ans;
    }
}