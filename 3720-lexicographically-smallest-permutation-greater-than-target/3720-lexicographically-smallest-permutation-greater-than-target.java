class Solution {
    String ans ;
    boolean f(int[] cnt , ArrayList<Character>path , String target , boolean big){
        int n = target.length();
        if(!ans.isEmpty()) return true;
        if(path.size() == n){
            if(big){
                StringBuilder sb = new StringBuilder();
                for(char c : path) sb.append(c);
                ans = sb.toString();
                return true;
            }
            return false;
        }
        
        int i = path.size();
        for(int j = 0 ;  j < 26 ; j++){
            if(cnt[j] == 0) continue;
            if(!big && j + 'a' < target.charAt(i)) continue;
            path.add((char)(j + 'a'));
            cnt[j]--;
            boolean newbig = big || (j + 'a' > target.charAt(i));

            if(f(cnt , path , target , newbig) == true) return true;

            path.remove(path.size() - 1);
            cnt[j]++;
        }
        return false;
    } 
    public String lexGreaterPermutation(String s, String target) {
        int n = s.length();
        int[] cnt = new int[26];
        for(char c : s.toCharArray()){
            cnt[c - 'a']++;
        }

        ans = "";
        ArrayList<Character> path = new ArrayList<>();
        f(cnt , path , target , false);
        return ans;
    }
}