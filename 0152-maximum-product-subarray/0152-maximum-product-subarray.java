class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int maxi = 1;
        int mini = 1;
        int ans = Integer.MIN_VALUE;
        for(int i = 0 ; i < n ;i++){
            if(nums[i] < 0){
                int temp = maxi;
                maxi = mini;
                mini = temp;
            }
            maxi = Math.max(nums[i] , nums[i] * maxi);
            mini = Math.min(nums[i] , nums[i] * mini);
            ans = Math.max(ans , Math.max(maxi , mini));
            ans = Math.max(ans , nums[i]);
        }
        return ans;
    }
}