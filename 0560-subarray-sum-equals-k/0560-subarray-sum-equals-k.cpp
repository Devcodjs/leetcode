class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int , int> mp;
        mp[0] = 1;
        int pref = 0;
        for(int i =  0 ; i < n ; i++){
            pref += nums[i];
            int d = pref - k;
            if(mp.find(d) != mp.end()){
                ans += mp[d];
            }
            mp[pref]++;
        }
        return ans; 
    }
};