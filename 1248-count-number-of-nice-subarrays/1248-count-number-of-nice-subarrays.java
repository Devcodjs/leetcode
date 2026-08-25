class Solution {
    int f(int[] nums , int k){
        int n = nums.length;
        int cnt = 0;
        int odd = 0;
        int l = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] % 2 != 0) odd++;
            while(odd > k){
                if(nums[l] % 2 != 0) odd--;
                l++;
            }
            cnt += (i - l + 1);
        }
        return cnt;
    }
    public int numberOfSubarrays(int[] nums, int k) {
        return f(nums , k ) - f(nums , k - 1);
    }
}