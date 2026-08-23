class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int fardest = 0;
        int end = 0;
        int cnt = 0;
        for(int i = 0 ;i < n - 1; i++){
            fardest = Math.max(fardest, nums[i] + i);
            if(i == end){
                cnt++;
                end = fardest;
            }
        }
        return cnt;
    }
}