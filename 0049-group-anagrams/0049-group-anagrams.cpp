class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        unordered_map<string , vector<string>> mp;
        for(auto& e : strs){
            string p = e;
            sort(e.begin() , e.end());
            mp[e].push_back(p);
        }
        for(auto& e : mp){
            ans.push_back(e.second);
        }
        return ans;
    }
};