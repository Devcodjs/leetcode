class Solution {
    public int[] findOrder(int num, int[][] pre) {
        int n = pre.length;
        int[] ans = new int[num];
        int[] ind = new int[num];
        List<List<Integer>> adj = new ArrayList<>(n);
        for(int i = 0 ; i < num ; i++){
            adj.add(new ArrayList<>());
        }
        for(int i = 0 ; i < n ; i++){
            int u = pre[i][0];
            int v = pre[i][1];
            adj.get(v).add(u);
            ind[u]++;
        }
        int cnt = 0;
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0 ; i < num; i++){
            if(ind[i] == 0){
                cnt++;
                q.offer(i);
            }
        }
        int i = 0;
        while(!q.isEmpty()){
            int node = q.peek();
            ans[i++] = node;
            q.poll();
            for(int e : adj.get(node)){
                ind[e]--;
                if(ind[e] == 0){
                    cnt++;
                    q.offer(e);
                }
            }
        }
        if(cnt == num) return ans;
        return new int[0];
    }
}