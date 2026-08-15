class Solution {
    boolean canEat(int[] piles, int h , int mid){
        long  n = piles.length;
        long cnt = 0;
        for(int x : piles){
            cnt += (x + mid - 1) / mid;
        }
        return cnt <= h;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        int l =  1 , r = Arrays.stream(piles).max().getAsInt();
        int ans = Integer.MAX_VALUE;
        while(l <= r){
            int mid = (l + r) / 2;
            if(canEat(piles , h , mid)){
                ans = Math.min(ans, mid);
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
}