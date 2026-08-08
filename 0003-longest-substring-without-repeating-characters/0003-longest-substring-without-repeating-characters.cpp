class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 1;
        if(n == 0) return 0;
        unordered_map<char , int> mp;
        int l = 0;
        for(int i = 0 ; i < n ; i++){
            mp[s[i]]++;
            while(mp[s[i]] > 1){
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            maxi = max(maxi , i - l + 1);
        }
        return maxi;
    }
};