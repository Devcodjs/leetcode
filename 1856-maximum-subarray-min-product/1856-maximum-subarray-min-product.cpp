class Solution {
public:
    #define MOD 1000000007
    void pse(vector<int>& prefMin , vector<int>& nums){
        int n = nums.size();
        prefMin[0] = -1;
        stack<int> st;
        st.push(0);
        for(int i = 1 ; i < n ; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()) prefMin[i] = -1;
            else{
                prefMin[i]  = st.top();
            }
            st.push(i);
        }
    }
    void nse(vector<int>& suffMin , vector<int>& nums){
        int n = nums.size();
        suffMin[n - 1] = n;
        stack<int> st;
        st.push( n - 1);
        for(int i = n - 2 ; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()) suffMin[i] = n;
            else{
                suffMin[i]  = st.top();
            }
            st.push(i);
        }
    }
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMin(n) , suffMin(n);
        pse(prefMin , nums);
        nse(suffMin , nums);

        long long maxi = 0;

        vector<long long> prefs(n + 1 , 0);
        for(int i = 0 ; i < n ; i++){
            prefs[i + 1] = prefs[i] + nums[i]; 
        }

        for(int i = 0 ; i < n ; i++){
            int p = prefMin[i] ;
            int s = suffMin[i];
            long long sum = (prefs[s] - prefs[p + 1]);
            long long prod = 1LL * nums[i] * sum;
            maxi = max(maxi , prod);
        }
        return maxi % MOD;
    }
};