class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long maxi = Long.MIN_VALUE;
        long[] pref = new long[n + 1];
        for(int i = 0 ; i < n ; i++){
            pref[i + 1]  = pref[i] + nums[i];
        }
        for(int i =  0; i < k ; i++){
            long cursum = 0;
            for(int j = i ; j < n ; j += k){
                int e = j + k - 1;
                if(e >= n)break;
                long subsum = pref[e + 1] - pref[j];
                cursum = Math.max(subsum , cursum + subsum);
                maxi = Math.max(maxi , cursum); 
            }
        }
        return maxi;
    }
}