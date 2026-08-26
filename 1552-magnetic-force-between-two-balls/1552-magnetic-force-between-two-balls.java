class Solution {
    boolean isCan(int[] pos , int  m , int mid){
        int n = pos.length;
        int cnt = 1;
        int l = 0;
        for(int i = 0  ; i < n ; i++){
            if((pos[i] - pos[l]) >= mid){
                cnt++;
                l = i;
            }
        }
        return cnt >= m;
    }
    public int maxDistance(int[] position, int m) {
        int n = position.length;
        Arrays.sort(position);
        int l = 0 ; int r = position[n - 1] - position[0];
        int ans = 0;
        while(l <= r){
            int mid = (l + r)  / 2;
            if(isCan(position , m , mid)){
                ans = Math.max(ans , mid);
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        } 
        return ans;
    }
}