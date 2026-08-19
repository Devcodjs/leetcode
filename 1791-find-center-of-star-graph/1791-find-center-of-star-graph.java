class Solution {
    public int findCenter(int[][] edges) {
        int n = edges.length;
        HashMap<Integer , Integer> mp = new HashMap<>();
        for(int i = 0 ; i < n ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            mp.put(u , mp.getOrDefault(u , 0) + 1);
            mp.put(v , mp.getOrDefault(v , 0) + 1);
        }
        int maxi = 0;
        int ans = 0;
        for(Map.Entry<Integer , Integer> entry : mp.entrySet()){
            int key = entry.getKey();
            int val = entry.getValue();
            if(maxi < val){
                ans = key;
                maxi = val;
            }
        }
        return ans;
    }
}