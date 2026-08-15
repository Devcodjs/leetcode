class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int end = 0;
        int fardest = 0;
        int cnt = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            fardest  = Math.max(nums[i] + i , fardest);
            if(i == end){
                cnt++;
                end = fardest;
            }
            if(i >= n - 1) return cnt;
        }
        return cnt;
    }
}