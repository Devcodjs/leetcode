class Solution {
    public int maxProfit(int[] nums) {
        int n = nums.length;
        int[] cur = new int[n + 1];
        int[] next = new int[n + 1];
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = 0  ; j < 2 ; j++){
                int take = 0;
                if(j == 0){
                    take = Math.max( next[1] - nums[i] , next[0]);
                }else{
                    take = Math.max(nums[i] + next[0] , next[1]);
                }
                int notTake = next[j];
                cur[j] = Math.max(take , notTake);
            }
            next = cur;
        }
        return cur[0];
    }
}