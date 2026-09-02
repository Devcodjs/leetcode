class Solution {
    public int minRefuelStops(int target, int s, int[][] stations) {
        int n = stations.length;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        int ans = 0;
        int cur = s;
        for(int i = 0 ; i <= n ; i++){
            while ((i < n && cur < stations[i][0]) || (i == n && cur < target)) {
                if (pq.isEmpty()) return -1;
                cur -= pq.poll();
                ans++;
            }
            if (i != n) pq.offer(-stations[i][1]);
        }
        return ans;

    }
}