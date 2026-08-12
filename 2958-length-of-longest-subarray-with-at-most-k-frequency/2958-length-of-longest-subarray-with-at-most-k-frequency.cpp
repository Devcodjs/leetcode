class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0 , r = 0;
        unordered_map<long long , int> mp;
        int maxi = 0;
        while(r < n){
            mp[nums[r]]++;
            if(mp[nums[r]] > k){
                maxi = max(r - l  , maxi);
                while( mp[nums[r]] > k){
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0) mp.erase(nums[l]);
                    l++;
                }
            }
            r++;
        }
        maxi = max(r - l , maxi);
        return maxi;
    }
};