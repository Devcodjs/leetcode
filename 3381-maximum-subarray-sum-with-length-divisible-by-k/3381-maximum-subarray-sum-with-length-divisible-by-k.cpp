class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxi = LLONG_MIN;
        vector<long long> pref(n + 1 , 0);
        for(int i = 0; i < n; i++){
            pref[i + 1] = pref[i] + (long long)nums[i]; 
        }
        for(int i = 0 ; i < k ; i++){
            long long cursum = 0;
            for(int j = i ; j < n ; j += k){
                int e = j + k - 1;
                if(e >= n) break;
                long long subArrsum = 0;
                subArrsum = pref[e + 1] - pref[j];
                cursum = max(cursum + subArrsum , subArrsum);
                maxi = max(maxi, cursum);
            }
        }
        return maxi;
    }
};