class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int , int> mp;
        mp[0] = 1;
        int prefs = 0;
        for(int i =  0 ; i < n ; i++){
            prefs += nums[i];
            int diff = prefs - k;
            if(mp.find(diff) != mp.end()){
                ans += mp[diff];
            }
            mp[prefs]++;
        }
        return ans; 
    }
};