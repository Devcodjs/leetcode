class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<int[]>> adj = new ArrayList<>(n + 1);
        for(int i = 0 ; i <= n ; i++){
            adj.add(new ArrayList<>());
        }
        for(int i = 0 ; i < times.length ; i++){
            int u = times[i][0] , v = times[i][1] , w = times[i][2];
            adj.get(u).add(new int[]{v , w});
        }
        Queue<int[]> q = new LinkedList<>();
        int[] dist = new int[n + 1];
        Arrays.fill(dist , Integer.MAX_VALUE);
        dist[k] = 0;
        q.offer(new int[]{k , 0});
        while(!q.isEmpty()){
            int[] p = q.peek();
            int node = p[0];
            int t = p[1];
            q.poll();
            if(dist[node] < t) continue;
            for(int[] i : adj.get(node)){
                int newr = i[0];
                int newt = i[1];
                if(dist[newr] > t + newt){
                    dist[newr] = t + newt;
                    q.offer(new int[]{newr , t + newt});
                }
            }
        }
        int ans = Integer.MIN_VALUE;
        for(int i = 1 ; i <= n ; i++){
            ans = Math.max(ans , dist[i]);
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}