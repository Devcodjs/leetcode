class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> mp;
        for(int x: nums) mp[x]++;
        int maxi = 0;
        for(auto& e : mp){
            maxi = max(maxi , e.second);
        }
        int ans = 0;
        for(auto& e : mp){
            if(e.second == maxi) ans += maxi;
        }
        return ans;
    }
};