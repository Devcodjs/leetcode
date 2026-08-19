class Solution {
    public List<String> findAllRecipes(String[] rec, List<List<String>> ing, String[] sup) {
        int n = rec.length;
        HashSet<String> st = new HashSet<>(Arrays.asList(sup));
        HashMap<String , Integer> mp = new HashMap<>();
        HashMap<String , List<Integer>> adj = new HashMap<>();
        int[] ind = new int[n];
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0 ; i < n; i++){
            for(String s : ing.get(i)){
                if(!st.contains(s)){
                    adj.putIfAbsent(s , new ArrayList<>());
                    adj.get(s).add(i);
                    ind[i]++;
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(ind[i] == 0) q.offer(i);
        }
        List<String> ans = new ArrayList<>();
        while(!q.isEmpty()){
            int i = q.peek();
            q.poll();
            ans.add(rec[i]);
            for(int j : adj.getOrDefault(rec[i] , new ArrayList<>())){
                ind[j]--;
                if(ind[j] == 0) q.offer(j);
            }
        }
        return ans;
    }
}