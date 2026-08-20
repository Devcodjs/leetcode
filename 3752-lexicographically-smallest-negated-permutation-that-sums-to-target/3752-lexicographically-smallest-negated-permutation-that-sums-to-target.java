class Solution {
    public int[] lexSmallestNegatedPerm(int n, long target) {
        long maxi = (long) n * (n + 1) / 2;
        long mini = - maxi;
        if(target < mini || target > maxi ||(maxi - target) % 2 != 0) return new int[0];
        long diff = (maxi - target) / 2;
        int[] ans = new int[n];
        for(int i = n ; i >= 1 ; i--){
            if(diff >= i){
                ans[i - 1] = -i;
                diff -= i;
            }else{
                ans[i - 1] = i;
            }
        }
        Arrays.sort(ans);
        return ans;
    }
}