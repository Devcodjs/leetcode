class Solution {
    public int largestRectangleArea(int[] nums) {
        int n = nums.length;
        int maxi = 0;
        Stack<Integer> s = new Stack<>();
        for(int i = 0 ; i < n ; i++){
            while(!s.isEmpty() && nums[s.peek()] > nums[i]){
                int nse = i;
                int ele = nums[s.peek()];
                s.pop();
                int pse = s.isEmpty() ? -1 : s.peek();
                maxi = Math.max(maxi , (nse - pse - 1) * ele);
            }
            s.push(i);
        }
        while(!s.isEmpty()){
            int nse = n;
            int ele = nums[s.peek()];
            s.pop();
            int pse = s.isEmpty() ? -1 : s.peek();
            maxi = Math.max(maxi , (nse - pse - 1) * ele);
        }
        return maxi;
    }
}