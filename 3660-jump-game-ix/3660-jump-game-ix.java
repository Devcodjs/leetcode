class Solution {
    public int[] maxValue(int[] nums) {
        int n = nums.length;
        int[] prefM = new int[n];
        int[] sufM = new int[n];
        prefM[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            prefM[i] = Math.max(prefM[i - 1] , nums[i]);
        }

        sufM[n - 1] = nums[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--){
            sufM[i] = Math.min(sufM[i + 1] , nums[i]);
        }

        int[] ans = new int[n];
        ans[n - 1] = prefM[n - 1];
        for(int i = n - 2 ; i>= 0 ; i--){
            if(prefM[i] <= sufM[i + 1]){
                ans[i] = prefM[i];
            }else{
                ans[i] = ans[i + 1];
            }
        }
        return ans;
    }
}