class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        int n = intervals.length;
        int cnt = 0;
        Arrays.sort(intervals , (a , b)-> a[0] - b[0]);
        int u = intervals[0][0] , v = intervals[0][1];
        for(int i = 1 ; i < n ; i++){
            int e = intervals[i][0] , f = intervals[i][1];
            if(v <= e){
                u = e;
                v = f;
            }else{
                cnt++;
                u = Math.min(u , e);
                v = Math.min(v, f);
            }
        }
        return cnt;
    }
}