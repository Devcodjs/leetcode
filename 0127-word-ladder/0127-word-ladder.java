class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int n = wordList.size();
        HashMap<String , Integer> mp = new HashMap<>();
        for(String s : wordList){
            mp.put(s , mp.getOrDefault(s , 0) + 1);
        }
        Queue<Pair<String , Integer>> q = new LinkedList<>();
        q.offer(new Pair<>(beginWord , 1));
        mp.remove(beginWord);
        while(!q.isEmpty()){
            String s = q.peek().getKey();
            int t = q.peek().getValue();
            q.poll();
            if(s.equals(endWord)) return t;
            int m = s.length();
            for(int i = 0 ; i < m ; i++){
                for(char j = 'a' ; j <= 'z' ; j++){
                    String ns = s.substring(0 , i) + j + s.substring(i + 1);
                    if(mp.containsKey(ns)){
                        q.offer(new Pair<>(ns , t + 1));
                        mp.remove(ns);
                    }
                }
            }
        }
        return 0;
    }
}