class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> arr(n + 1);
        unordered_map<int , int> mp;
        for(auto& e : nums){
            mp[e]++;
        }
        for(auto& e : mp){
            arr[e.second].push_back(e.first);
        }
        for(int i = n ; i >= 0 ;i--){
            for(auto& e : arr[i]){
                if(k > 0){
                    ans.push_back(e);
                    k--;
                }
            }
        }
        return ans;
    }
};