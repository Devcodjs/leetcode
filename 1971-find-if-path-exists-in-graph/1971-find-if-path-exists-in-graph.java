class Solution {
    public boolean validPath(int n, int[][] edges, int s, int d) {
        int m = edges.length;
        List<List<Integer>> adj = new ArrayList<>();
        for(int i =  0 ; i < n ; i++){
            adj.add(new ArrayList<>());
        }
        for(int i = 0 ; i < m; i++){
            int u = edges[i][0] , v = edges[i][1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        Queue<Integer> q = new LinkedList<>();
        q.offer(s);
        int[] vis = new int[n];
        vis[s] = 1;
        while(!q.isEmpty()){
            int node = q.peek();
            q.poll();
            if(node == d) return true;
            for(int e : adj.get(node)){
               if(vis[e] != 1){
                q.offer(e);
                vis[e] = 1;
               }
            }
        }
        return false;
    }
}