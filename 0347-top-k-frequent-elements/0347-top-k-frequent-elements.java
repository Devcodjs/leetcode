class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer , Integer> mp = new HashMap<>();
        int n = nums.length;
        ArrayList<Integer>[] ans = new ArrayList[n + 1];
        for(int i = 0 ; i < n ; i++){
            mp.put(nums[i] , mp.getOrDefault(nums[i] , 0) + 1);
        }
        for(Map.Entry<Integer , Integer>entry : mp.entrySet()){
            int val = entry.getKey();
            int idx = entry.getValue();
            if(ans[idx] == null){
                ans[idx] = new ArrayList<>();
            }
            ans[idx].add(val);
        }
        int[] res = new int[k];
        int idx = 0;
        for(int i = n ; i >= 0 && idx < k ;i--){
            if(ans[i] != null){
                for(int p : ans[i]){
                    res[idx++] = p;
                    if(idx == k) break;
                }
            }
        }
        return res;
    }
}