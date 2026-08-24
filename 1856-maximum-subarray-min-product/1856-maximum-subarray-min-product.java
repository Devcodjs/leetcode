class Solution {
    static final int MOD =  1000000007;
    void nse(int[] suf , int[] nums){
        int n = nums.length;
        Stack<Integer> st = new Stack<>();
        st.push(n - 1);
        suf[n - 1] = n;
        for(int i = n - 2 ; i >= 0 ;i--){
            while(!st.isEmpty() && nums[st.peek()] >= nums[i]){
                st.pop();
            }
            if(st.isEmpty()) suf[i] = n;
            else{
                suf[i] = st.peek();
            }
            st.push(i); 
        }
    }
    void pse(int[] pref , int[] nums){
        int n = nums.length;
        Stack<Integer> st = new Stack<>();
        st.push(0);
        pref[0] = -1;
        for(int i = 1 ; i < n ; i++){
            while(!st.isEmpty() && nums[st.peek()] >= nums[i]){
                st.pop();
            }
            if(st.isEmpty()) pref[i] = -1;
            else{
                pref[i] = st.peek();
            } 
            st.push(i);
        }
    }
    public int maxSumMinProduct(int[] nums) {
        int n = nums.length;
        int[] suf = new int[n];
        int[] pref = new int[n];
        nse(suf , nums);
        pse(pref , nums);

        long[] ps = new long[n + 1];
        for(int i = 0  ; i < n ; i++){
            ps[i + 1] = nums[i] + ps[i];
        }
        
        long maxi  = 0;
        for(int i = 0 ; i < n ; i++){
            int s = suf[i];
            int p = pref[i];
            long sum = ps[s] - ps[p + 1];
            long prod = 1L * nums[i] * sum;
            maxi = Math.max(maxi , prod);
        }
        return (int)(maxi % MOD);
    }
}