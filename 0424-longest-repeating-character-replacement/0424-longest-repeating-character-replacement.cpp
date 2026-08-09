class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlenght = 0;
        int maxf = 0;
        int cnt = 1;
        unordered_map<char , int> mp;
        int l = 0 , r = 0;
        while(r < n){
            mp[s[r]]++;
            maxf  = max(maxf , mp[s[r]]);
            if(r - l + 1 - maxf <= k){
                maxlenght = max(maxlenght , r - l + 1);
            }
            if(r - l + 1 - maxf > k){
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return maxlenght;
    }
};