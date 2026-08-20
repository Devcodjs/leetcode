class Solution {
    boolean dfs(int[][] graph , int[] vis , int i , int col){
        vis[i] = col;
        for(int e : graph[i]){
            if(vis[e] == -1){
                if(dfs(graph , vis , e ,1- col) == false) return false;
            }else if(vis[e] == col) return false;
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] vis = new int[n];
        Arrays.fill(vis , -1);
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == -1)if(dfs(graph , vis , i , 0) == false) return false;
        }
        return true;
    }
}