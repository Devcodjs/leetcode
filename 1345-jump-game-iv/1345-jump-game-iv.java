class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;
        HashMap<Integer , List<Integer>> mp = new HashMap<>(n);
        for(int i =  0;i < n ;i++){
            mp.put(arr[i] , new ArrayList<>());
        }
        for(int i = 0 ; i < n ;i++){
            mp.get(arr[i]).add(i);
        }
        int[] dist = new int[n];
        Arrays.fill(dist , Integer.MAX_VALUE);
        dist[0] = 0;
        int[] vis = new int[n];
        vis[0] = 1;
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0 , 0});
        while(!q.isEmpty()){
            int[] p = q.peek();
            q.poll();
            int node = p[0];
            int d = p[1];
            if(dist[node] < d) continue;
            // jumps to the same value....
            for(int e : mp.get(arr[node])){
                if(dist[e] > 1 + d && vis[e] == 0){
                    dist[e] = 1 + d;
                    vis[e] = 1;
                    q.offer(new int[]{e , 1 + d});
                }
            }
            mp.get(arr[node]).clear();
            // n - 1 jump
            if(node - 1 >= 0 && vis[node - 1] == 0){
                dist[node - 1] = 1 + d;
                q.offer(new int[]{node - 1 , 1 + d});
                vis[node - 1] = 1;
            }

            // n + 1 jumps ....
            if(node + 1 < n && vis[node + 1] == 0){
                dist[node + 1] = 1 + d;
                q.offer(new int[]{node + 1 , 1 + d});
                vis[node + 1] = 1;
            }
        }
        return dist[n - 1];
    }
}