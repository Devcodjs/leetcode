class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals , (a , b)-> a[0] - b[0]);
        List<List<Integer>> ans = new ArrayList<>();
        int u = intervals[0][0] , v = intervals[0][1];
        for(int i = 1; i < n ; i++){
            int e = intervals[i][0] , f = intervals[i][1];
            if(v < e){
                ans.add(List.of(u , v));
                u = e;
                v = f;
            }else{
                u = Math.min(u , e);
                v = Math.max(v , f);
            }
        }
        ans.add(List.of(u , v));
        int[][] res = new int[ans.size()][2];
        for(int i = 0 ; i < ans.size() ; i++){
            res[i][0] = ans.get(i).get(0);
            res[i][1] = ans.get(i).get(1);
        }
        return res;
    }
}