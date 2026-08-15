class Solution {
    boolean isCan(int[] weights , int days , int mid){
        int d = 1;
        int sum = 0;
        for(int x : weights){
            if(sum + x <= mid){
                sum += x;
                continue;
            }else{
                d++;
                sum = x;
            }
        }
        return d <= days;
    }
    public int shipWithinDays(int[] weights, int days) {
        int n = weights.length;
        int l = Arrays.stream(weights).max().getAsInt();
        int r = Arrays.stream(weights).sum();
        int ans = Integer.MAX_VALUE;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(isCan(weights , days, mid)){
                ans = Math.min(ans , mid);
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return ans;
    }
}