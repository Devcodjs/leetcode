class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> pref(n , 1) , suff(n , 1);
        int prod = nums[0];
        for(int i = 1 ; i < n ; i++){
            pref[i] = prod;
            prod *= nums[i];
        }
        prod = nums[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--){
            suff[i] = prod;
            prod *= nums[i];
        }

        for(int i = 0 ; i< n ; i++){
            ans.push_back(pref[i] * suff[i]);
        }
        return ans;
    } 
};