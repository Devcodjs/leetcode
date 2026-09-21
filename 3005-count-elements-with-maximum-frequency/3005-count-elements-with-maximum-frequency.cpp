class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> mp;
        for(int x: nums) mp[x]++;
        vector<int> buck(n + 1);
        for(auto& e : mp){
            buck[e.second]++;
        }
        int ans = 0;
         for(int x: buck) cout<<x<<" ";
        for(int i = n ; i >= 0 ;i--){
            if(buck[i] == 0) continue;
            else{
                ans = i * buck[i];
                break;
            }
        }
        return ans;
    }
};