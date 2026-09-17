class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int l = 0;
        unordered_map<char , int> mp;
        for(int r = 0; r < n ; r++){
            while (mp[s[r]] > 0) {
                    mp[s[l]]--;
                    if(mp[s[l]] == 0)mp.erase(s[l]);
                    l++;
            }
            mp[s[r]]++;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};