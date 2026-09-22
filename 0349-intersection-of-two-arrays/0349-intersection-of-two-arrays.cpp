class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        if(n > m) return intersection(nums2 , nums1);
        unordered_map<int , int> mp;
        vector<int> ans;
        for(auto& e : nums2) mp[e]++;
        for(int i = 0 ; i < n;i++){
            if(mp.find(nums1[i]) != mp.end()){
                ans.push_back(nums1[i]);
                mp.erase(nums1[i]);
            }
        }
        return ans;
    }
};