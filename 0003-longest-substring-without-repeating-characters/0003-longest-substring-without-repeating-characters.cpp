class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        int l = 0 , r = 0;
        unordered_map<char , int> mp;
        while(r < n){
            mp[s[r]]++;
            if(s[r] > 1){
                maxi = max(maxi , r - l );
                while(mp[s[r]] > 1){
                    mp[s[l]]--;
                    l++;
                }
            }
            r++;
        }
        maxi = max(maxi , r - l );
        return maxi;
    }
};