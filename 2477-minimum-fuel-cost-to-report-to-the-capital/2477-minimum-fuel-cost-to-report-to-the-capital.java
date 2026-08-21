class Solution {
    long ans = 0;
    long dfs(List<List<Integer>> adj , int seats, int node , int par){
        long p = 1;
        for(int i : adj.get(node)){
            if(i == par) continue;
            long x = dfs(adj , seats , i , node);
            p += x;
            ans += (x + seats - 1) / seats;
        }
        return p;
    }

    public long minimumFuelCost(int[][] roads, int seats) {
        int n = roads.length;
        List<List<Integer>> adj = new ArrayList<>(n + 1);
        for(int i = 0 ; i <= n ; i++){
            adj.add(new ArrayList<>());
        }
        for(int i = 0 ; i < n ;i++){
            int u = roads[i][0] , v = roads[i][1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        dfs(adj , seats , 0 , -1);
        return ans;
    }
}