class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        int[] vis = new int[n];
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        vis[start] = 1;
        while(!q.isEmpty()){
            int node = q.peek();
            q.poll();
            if(arr[node] == 0) return true;

            int left = node - arr[node];
            int right = node + arr[node];

            if(left >= 0 && vis[left] == 0){
                q.offer(left);
                vis[left] = 1;
            }
            if(right < n && vis[right] == 0){
                q.offer(right);
                vis[right] = 1;
            }
        }
        return false;
    }
}