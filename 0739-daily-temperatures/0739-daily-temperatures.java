class Solution {
    public int[] dailyTemperatures(int[] temp) {
        int n = temp.length;
        int[] ans = new int[n];
        Stack<int[]> st = new Stack<>();
        st.push(new int[]{temp[n - 1] , n - 1});
        for(int i = n - 2 ; i >= 0 ; i--){
            while(!st.isEmpty() && temp[i] >= st.peek()[0]){
                st.pop();
            }
            if(!st.isEmpty()) ans[i] = st.peek()[1] - i;
            st.push(new int[]{temp[i] , i});
        }
        return ans;
    }
}